using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CodeJAM {
    partial class MainWindow {

        private string Process(){
            return problem3();
        }

        private string problem3(){
            string[] lines = _input.Split(new string[] { "\r\n", "\n" }, StringSplitOptions.None);
            int tests = Int32.Parse(lines[0]);
            string outputBuffer = "";
            List< int > previousValues = new List<int>();

            for (int tc = 1; tc < lines.Length - 1; tc++) {
                string[] nums = lines[tc].Split(' ');

                int min = Int32.Parse(nums[0]);
                int max = Int32.Parse(nums[1]);
                int recycled = 0;

                int temp = min;
                int digitNum = 0;
                while (temp > 0) {
                    temp = temp / 10;
                    digitNum++;
                }

                for (int i = min; i <= max; i++){
                    //check if number is formed by only one digit and find out how many digits it has
                    int d = i % 10;
                    bool ok = true;
                    temp = i / 10;
                    while (temp > 0){
                        if (temp % 10 != d){
                            ok = false;
                            break;
                        }
                        temp = temp/10;
                    }
                    if (ok) continue;

                    //if (tc == 4) outputBuffer += "\r\n" + i + " - ";

                    previousValues.Clear();
                    string num = i + "";
                    for (int j = 1; j < digitNum; j++) {
                        string s = num.Substring(j) + num.Substring(0, j);
                        temp = Int32.Parse(s);

                        if (temp >= min && temp <= max && temp > i && !previousValues.Contains(temp)) {
                            recycled++;
                            previousValues.Add(temp);
                            //if (tc == 4) outputBuffer += temp + " ";
                        }
                    }

                    /*temp = i;
                    for (int j = 1; j < digitNum; j++){
                        temp = temp % 10 * multiplyBy + temp / 10;

                        if (temp >= min && temp <= max) recycled++;
                    }*/
                }

                outputBuffer += "Case #" + tc + ": " + recycled + "\r\n";

            }

            return outputBuffer;
        }

        private string problem2(){
            string[] lines = _input.Split(new string[] { "\r\n", "\n" }, StringSplitOptions.None);
            int tests = Int32.Parse(lines[0]);
            string outputBuffer = "";

            for (int i = 1; i < lines.Length - 1; i++){
                string[] nums = lines[i].Split(' ');
                int n = Int32.Parse(nums[0]);
                int surprises = Int32.Parse(nums[1]);
                int p = Int32.Parse(nums[2]);
                int howMany = 0;
                //int[] scores = new int[n];

                for (int j = 3; j < n + 3; j++){
                    int score = Int32.Parse(nums[j]);
                    int minScore = 0;
                    if (p > 0) minScore = p * 3 - 2;

                    if (score >= minScore) howMany++;
                    else{
                        minScore = Math.Max(p*3 - 4, 1);
                        if (surprises > 0 && score >= minScore){
                            surprises--;
                            howMany++;
                        }
                    }
                }

                outputBuffer += "Case #" + i + ": " + howMany + "\r\n";
            }

            return outputBuffer;
        }

        private string problem1(){
            string[] lines = _input.Split(new string[] { "\r\n", "\n" }, StringSplitOptions.None);
            int tests = Int32.Parse(lines[0]);
            string outputBuffer = "";

            Dictionary<char, char> dict = new Dictionary<char, char>();
            dict.Add('y', 'a');
            dict.Add('n', 'b');
            dict.Add('f', 'c');
            dict.Add('i', 'd');
            dict.Add('c', 'e');
            dict.Add('w', 'f');
            dict.Add('l', 'g');
            dict.Add('b', 'h');
            dict.Add('k', 'i');
            dict.Add('u', 'j');
            dict.Add('o', 'k');
            dict.Add('m', 'l');
            dict.Add('x', 'm');
            dict.Add('s', 'n');
            dict.Add('e', 'o');
            dict.Add('v', 'p');
            dict.Add('z', 'q');
            dict.Add('p', 'r');
            dict.Add('d', 's');
            dict.Add('r', 't');
            dict.Add('j', 'u');
            dict.Add('g', 'v');
            dict.Add('t', 'w');
            dict.Add('h', 'x');
            dict.Add('a', 'y');
            dict.Add('q', 'z');

            for (int i = 1; i < lines.Length - 1; i++){
                string[] words = lines[i].Split(' ');
                outputBuffer += "Case #" + i + ": ";

                foreach (string word in words){
                    for (int j = 0; j < word.Length; j++) outputBuffer += dict[word[j]];

                    outputBuffer += " ";
                }

                outputBuffer += "\r\n";
            }

            return outputBuffer;
        }
    }
}
