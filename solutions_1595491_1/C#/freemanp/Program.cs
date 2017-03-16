using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CodeJAM {
    partial class MainWindow {

        private string Process(){
            return problem2();
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
