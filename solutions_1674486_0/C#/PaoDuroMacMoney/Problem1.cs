using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FirstRound.Problem1
{
    public class Problem1
    {
        private Dictionary<int, List<int>> m_Levels = new Dictionary<int,List<int>>();

        private int m_LevelToBeAdded = 1;

        public Problem1()
        {

        }

        public void addLevel(List<int> p_InheritanceList)
        {
            m_Levels.Add(m_LevelToBeAdded, p_InheritanceList);

            m_LevelToBeAdded++;
        }

        private bool[] m_BeenThisLevel ; 

        public bool checkHasDiamondInheritence()
        {
            for (int i = 1; i < m_LevelToBeAdded; i++)
            {
                m_BeenThisLevel = new bool[m_LevelToBeAdded - 1];
                m_BeenThisLevel[i-1] = true;
                if (markParents(i))
                {
                    return true;
                }
            }

            return false;
        }

        private bool markParents(int p_Level)
        {
            foreach(int v_Parent in m_Levels[p_Level])
            {
                if (v_Parent != 0)
                {
                    if (m_BeenThisLevel[v_Parent - 1])
                    {
                        return true;
                    }
                    else
                    {
                        m_BeenThisLevel[v_Parent - 1] = true;
                        if (markParents(v_Parent))
                        {
                            return true;
                        }
                    }
                }
            }
            return false;
        }
    }
}
