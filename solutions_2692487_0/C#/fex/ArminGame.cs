using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Dynamic
{
    class ArminGame
    {
        public int ArminSize { get; set; }
        public int OperationCounter;
        LinkedList<int> MotesSize;

        public ArminGame(int ArminSize, List<int> OtherMothesSize)
        {
            this.ArminSize = ArminSize;
            OperationCounter = 0;
            OtherMothesSize.Sort();
            MotesSize = new LinkedList<int>(OtherMothesSize);
            AbsorbInitializer();
        }

        // absorbs possible motes on the beginning
        private void AbsorbInitializer()
        {
            LinkedListNode<int> firstMote = MotesSize.First;
            while (firstMote != null)
            {
                if (firstMote.Value >= ArminSize)
                    break;
                else
                {
                    ArminSize += firstMote.Value;
                    firstMote = firstMote.Next;
                    MotesSize.RemoveFirst();
                }
            }
        }

        public int FindBestSolution()
        {
            LinkedListNode<int> firstMote = MotesSize.First;
            bool? isDeletionBetter = null;

            while (firstMote != null)
            {
                if (firstMote.Value < ArminSize)
                {
                    ArminSize += firstMote.Value;
                    firstMote = firstMote.Next;
                    MotesSize.RemoveFirst();
                }
                else
                {
//                    if ( isDeletionBetter == null )
                        isDeletionBetter = IsDeletionSolutionBetter();
                    if (isDeletionBetter == true)
                    {
                        OperationCounter += MotesSize.Count;
                        break;
                    }
                    else
                    {
                        ArminSize += (ArminSize - 1);
                        OperationCounter++;
                    }
                }
            }

            return OperationCounter;
        }

        private bool IsDeletionSolutionBetter()
        {
            LinkedList<int> cloneAdd = new LinkedList<int>();
            int arminSizeTemp = ArminSize;
            foreach (var val in MotesSize)
                cloneAdd.AddLast(val);
           

            int addCounter = 0;
            int deleteCounter = cloneAdd.Count;

            LinkedListNode<int> tempAdd = cloneAdd.First;

            if (arminSizeTemp != 1) // deletion will be always better in such case
            {
                while (cloneAdd.Any())
                {
                    if (arminSizeTemp <= tempAdd.Value)
                    {
                        arminSizeTemp += (arminSizeTemp - 1);
                        addCounter++;
                    }
                    else
                    {
                        arminSizeTemp += tempAdd.Value;
                        tempAdd = tempAdd.Next;
                        cloneAdd.RemoveFirst();
                    }
                }
            }
            else
                return true;

            if (addCounter > deleteCounter)
                return true;
            else
                return false;
        }

        
    }
}
