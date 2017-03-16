using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace TicTacToe
{
    class Program
    {
        static IList<KeysOfAType> avaiableKeys = new List<KeysOfAType>();

        static void Main(string[] args)
        {
            IList<string> resultsOfCases = GetInputsFromFile("D-small-attempt0.in");

            using (System.IO.StreamWriter file = new System.IO.StreamWriter("Output.txt"))
            {
                foreach (string line in resultsOfCases)
                {
                    file.WriteLine(line);
                }
            }
        }

        private static IList<string> GetInputsFromFile(string fileName)
        {
            IList<string> results = new List<string>();

            string[] lines = System.IO.File.ReadAllLines(fileName);
            int caseCount = 1;
            for (int i = 1; i < lines.Count(); )
            {
                List<Chest> aCase = new List<Chest>();
                avaiableKeys = new List<KeysOfAType>();

                GrabInitialKeys(lines[i + 1].Split(' ').Select(k => Int32.Parse(k)), avaiableKeys);

                int numberOfChests = Int32.Parse(lines[i].Split(' ')[1]);
                for (int j = 1; j <= numberOfChests; j++)
                {
                    var numbers =  lines[i + j + 1].Split(' ').Select(k => Int32.Parse(k)).ToList();
                    Chest aChest = new Chest(numbers[0]);
                    aChest.ChestLabel = j.ToString();

                    List<int> keysColl = new List<int>();
                    if (numbers.Count > 2)
                    {
                        for(int k = 2; k <= numbers.Count - 1; k++)
                        {
                            keysColl.Add(numbers[k]);
                        }
                    }

                    GrabInitialKeys(keysColl, aChest.treasureKeys);

                    aCase.Add(aChest);
                }
                string result = GetTheResultOfCase(aCase);
                results.Add("Case #" + caseCount + ":" + result);
                caseCount++;
                i = i + numberOfChests + 2;
            }

            return results; ;
        }

        private static void GrabInitialKeys(IEnumerable<int> keyTypes, IList<KeysOfAType> treasureKeys)
        {
            foreach(int keyType in keyTypes)
            {
                var keysOfAType = treasureKeys.FirstOrDefault(k => k.TypeOfKey == keyType);
              if (keysOfAType == null)
                  treasureKeys.Add(new KeysOfAType(keyType));
              else
                  keysOfAType.AddKey();
            }
        }

        private static string GetTheResultOfCase(List<Chest> aCase)
        {

            string result = string.Empty; 
            for (int i = 0; i < aCase.Count; i++)
            {
                string partialResult = OpenLeastNumberedChest(aCase);
                if (partialResult == null)
                    return " IMPOSSIBLE";
                else
                    result = result + " " + partialResult;

            }

            return result;

        }

        private static string OpenLeastNumberedChest(List<Chest> aCase)
        {
            IEnumerable<int> availbleKeyTypes = avaiableKeys.Select(ak => ak.TypeOfKey).ToList();

            foreach (int akt in availbleKeyTypes)
            {
               var openedChest = aCase.FirstOrDefault(ac => ac.TypeOfKey == akt && !ac.IsOpened);
                if(openedChest != null)
                {
                    RemoveKeyOfaType(akt);
                    openedChest.IsOpened = true;
                    foreach (var tresKey in openedChest.treasureKeys)
                    {
                        var keysOfAType = avaiableKeys.FirstOrDefault(k => k.TypeOfKey == tresKey.TypeOfKey);
                        if (keysOfAType == null)
                            avaiableKeys.Add(new KeysOfAType(tresKey.TypeOfKey, tresKey.Count));
                        else
                            keysOfAType.AddManyKey(tresKey.Count);

                    }
                    return openedChest.ChestLabel;
                }

            }

            return null;
        }

        private static void RemoveKeyOfaType(int akt)
        {
          var keysOfType =  avaiableKeys.First(a => a.TypeOfKey == akt);
          keysOfType.RemoveKey();
            if(!keysOfType.IsKeyAvailable())
                avaiableKeys.Remove(keysOfType);
        }

    }

    class KeysOfAType
    {
        public int TypeOfKey { get; private set; }
        public int Count = 0;
        public KeysOfAType(int typeOfKey)
        {
            TypeOfKey = typeOfKey;
            Count = 1;
        }

        public KeysOfAType(int typeOfKey, int count)
        {
            TypeOfKey = typeOfKey;
            Count = count;
        }

        public bool IsKeyAvailable() { return Count > 0; }
        public void AddKey() {  Count++; }
        public void AddManyKey(int count) { Count = Count + count; }

        public void RemoveKey()  { 
            if (IsKeyAvailable()) 
                Count--; 
        }
    }


    class Chest
    {
        public int TypeOfKey { get; private set; }
        public Chest(int typeOfKey)
        {
            TypeOfKey = typeOfKey;
            treasureKeys = new List<KeysOfAType>();
        }

        public bool IsOpened;

        public string ChestLabel;

        public IList<KeysOfAType> treasureKeys;
    }
}

