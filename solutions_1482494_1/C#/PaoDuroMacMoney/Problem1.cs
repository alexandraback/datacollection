using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FirstRound.Problem1
{
    public class Problem1
    {

        public static int DoTheMagic(int p_Levels, int[] p_StarsNeeded)
        {
            Dictionary<int,int?> m_LevelOneStar = new Dictionary<int,int?>();
            Dictionary<int,int?> m_LevelTwoStar = new Dictionary<int,int?>();

            int v_CurrentStars = 0;
            int v_IterationsNeeded = 0;
            
            int v_StarsNeeded = p_StarsNeeded.Count();

            for(int i = 0; i<p_StarsNeeded.Count()/2; i++)
            {
                m_LevelOneStar.Add(i,p_StarsNeeded[2*i]);
                m_LevelTwoStar.Add(i, p_StarsNeeded[2 * i + 1]);
            }

            while (m_LevelTwoStar.Count() > 0)
            {
                v_IterationsNeeded++;
                List<KeyValuePair<int,int?>> v_ItemValues = m_LevelTwoStar.Where(v_Value => v_Value.Value <= v_CurrentStars).ToList();
                KeyValuePair<int, int?> v_ItemValue;

                if (v_ItemValues.Count > 0)
                {
                    v_ItemValue = v_ItemValues.FirstOrDefault(v_Value => m_LevelOneStar.ContainsKey(v_Value.Key));
                    if (v_ItemValue.Equals(default(KeyValuePair<int, int?>)))
                    {
                        v_ItemValue = v_ItemValues.FirstOrDefault();
                    }

                    if (m_LevelOneStar.ContainsKey(v_ItemValue.Key))
                    {
                        m_LevelOneStar.Remove(v_ItemValue.Key);
                        v_CurrentStars++;
                    }
                    m_LevelTwoStar.Remove(v_ItemValue.Key);                    
                    v_CurrentStars ++;
                    continue;
                }

                v_ItemValues = m_LevelOneStar.Where(v_Value => v_Value.Value <= v_CurrentStars).ToList();
                if (v_ItemValues.Count > 0)
                {
                    v_ItemValue = v_ItemValues.OrderByDescending(v_Value => m_LevelTwoStar[v_Value.Key]).First();

                    if (!v_ItemValue.Equals(default(KeyValuePair<int, int?>)))
                    {
                        m_LevelOneStar.Remove(v_ItemValue.Key);
                        v_CurrentStars += 1;
                        continue;
                    }
                }
                return 0;
            }

            return v_IterationsNeeded;
        }
    }
}
