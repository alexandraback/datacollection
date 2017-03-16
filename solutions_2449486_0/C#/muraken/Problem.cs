using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace km.gcj
{
    class Problem
    {
        /// <summary> 入力ファイル名 </summary>
        protected readonly string pathInputFile;
        /// <summary> 出力ファイル名 </summary>
        protected readonly string pathOutputFile;

        /// <summary> 入力文字列の保持 </summary>
        protected IEnumerable<string> inputLines;
        /// <summary> 入力文字列の順次取り出し </summary>
        protected IEnumerator<string> ienum;

        /// <summary> 出力回答数 </summary>
        protected int answerCount = 0;


        #region 読み込み行の処理

        /// <summary> 入力ファイルより一行読み込む。 </summary>
        /// <returns>数値の配列</returns>
        public Int64[] getNextLineAsInt64Array() {
            return getNextInt64s().ToArray();
        }
        /// <summary> 入力ファイルより一行読み込む。 </summary>
        /// <returns>数値の列挙</returns>
        public IEnumerable<Int64> getNextInt64s() {
            if (!this.ienum.MoveNext()) {
                return null;
            }
            else {
                return this.ienum.Current.Split(' ').Select(str => Int64.Parse(str));
            }
        }
        /// <summary> 入力ファイルより一行読み込む。 </summary>
        /// <returns>数値の列挙</returns>
        public IEnumerable<double> getNextDoubles() {
            if (!this.ienum.MoveNext()) {
                return null;
            }
            else {
                return this.ienum.Current.Split(' ').Select(str => double.Parse(str));
            }
        }

        /// <summary> 入力ファイルより一行読み込む。 </summary>
        /// <returns>文字列の配列</returns>
        public string[] getNextLineAsStringArray() {
            return getNextStrs().ToArray();
        }
        /// <summary> 入力ファイルより一行読み込む。 </summary>
        /// <returns>文字列の列挙</returns>
        public IEnumerable<string> getNextStrs() {
            if (!this.ienum.MoveNext()) {
                return null;
            }
            else {
                return this.ienum.Current.Split(' ');
            }
        }

        /// <summary> 入力ファイルより一行読み込む。 </summary>
        /// <returns>文字列</returns>
        public string getNextLine() {
            if (!this.ienum.MoveNext()) {
                return null;
            }
            else {
                return this.ienum.Current;
            }
        }

        /// <summary> 入力ファイルより複数行読み込む。 </summary>
        /// <returns>文字列の列挙</returns>
        public IEnumerable<string> getNextLines(int cnt) {
            if (cnt <= 0) yield break;
            while (0 < cnt-- && this.ienum.MoveNext()) {
                yield return this.ienum.Current;
            }
        }

        /// <summary> 入力ファイルより複数行読み込む。 </summary>
        /// <returns>文字の列挙の列挙</returns>
        public IEnumerable<List<char>> getNextLinesChars(int cnt) {
            if (cnt <= 0) yield break;
            while (0 < cnt-- && this.ienum.MoveNext()) {
                yield return this.ienum.Current.ToCharArray().ToList();
            }
        }

        #endregion


        #region 回答処理
        /// <summary>
        /// 行のみで回答（文字列）する。
        /// Case #xx: line
        /// </summary>
        /// <param name="prmStr"></param>
        public void WriteAnswerFullLine(string prmStr) {
            FileInfo fOut = new FileInfo(this.pathOutputFile);
            using (StreamWriter sw = new StreamWriter(fOut.FullName, true)) {
                this.answerCount++;
                sw.WriteLine("Case #{0}: {1}", this.answerCount, prmStr);
                sw.Flush();
            }
        }

        /// <summary>
        /// 行のみで回答（数値：書式指定）する。
        /// Case #xx: 0.00000
        /// </summary>
        /// <param name="prmStr"></param>
        public void WriteAnswerFullLine(Double prmD, string prmFormat) {
            FileInfo fOut = new FileInfo(this.pathOutputFile);
            using (StreamWriter sw = new StreamWriter(fOut.FullName, true)) {
                this.answerCount++;
                sw.WriteLine("Case #{0}: {1:" + prmFormat + "}", this.answerCount, prmD);
                sw.Flush();
            }
        }

        /// <summary>
        /// 複数行で回答する。<br />
        /// Case #xx:<br />
        /// line01<br />
        /// line02<br />
        /// </summary>
        /// <param name="prmStr"></param>
        public void WriteAnswerMultiLine(string[] prmStrs) {
            FileInfo fOut = new FileInfo(this.pathOutputFile);
            using (StreamWriter sw = new StreamWriter(fOut.FullName, true)) {
                this.answerCount++;
                sw.WriteLine("Case #{0}:", this.answerCount);
                foreach (string str in prmStrs) {
                    sw.WriteLine("{0}", str);
                }
                sw.Flush();
            }
        }

        /// <summary>
        /// 配列で回答する。<br />
        /// Case #xx: [line1, line2, line3]<br />
        /// </summary>
        /// <param name="prmStr"></param>
        public void WriteAnswerMultiLineArray(string[] prmStrs) {
            FileInfo fOut = new FileInfo(this.pathOutputFile);
            using (StreamWriter sw = new StreamWriter(fOut.FullName, true)) {
                this.answerCount++;
                sw.WriteLine("Case #{0}: [{1}]", this.answerCount, string.Join(", ", prmStrs));
                sw.Flush();
            }
        }

        /// <summary>
        /// 回答ヘッダのみを書き出す。<br />
        /// Case #xx:<br />
        /// </summary>
        /// <param name="prmStr"></param>
        public void WriteAnswerHeader() {
            FileInfo fOut = new FileInfo(this.pathOutputFile);
            using (StreamWriter sw = new StreamWriter(fOut.FullName, true)) {
                this.answerCount++;
                sw.WriteLine("Case #{0}:", this.answerCount);
                sw.Flush();
            }
        }

        /// <summary>
        /// 行を書き出す。
        /// line
        /// </summary>
        /// <param name="prmStr"></param>
        public void WriteAnswerSubLine(string prmStr) {
            FileInfo fOut = new FileInfo(this.pathOutputFile);
            using (StreamWriter sw = new StreamWriter(fOut.FullName, true)) {
                sw.WriteLine("{0}", prmStr);
                sw.Flush();
            }
        }

        #endregion

        #region コンストラクタ、初期化処理
        private Problem() {
            inputLines = new List<string>();
        }

        private Problem(string pathIn, string pathOut)
            : this() {
            this.pathInputFile = pathIn;
            this.pathOutputFile = pathOut;
        }

        /// <summary>
        /// 初期化処理
        /// </summary>
        /// <param name="args"></param>
        /// <returns></returns>
        public static Problem createProblem(string[] args) {
            Problem ret;
            if (args.Length < 1) {
                Console.WriteLine("Error: arguments");
                return null;
            }
            ret = new Problem(args[0], args[0] + ".out");
            FileInfo fIn = new FileInfo(ret.pathInputFile);
            Console.WriteLine("reading..." + fIn.FullName);
            if (!fIn.Exists) {
                Console.WriteLine("Error: input file");
                return null;
            }
            // 入力ファイルを全部読み込む。
            List<string> input = new List<string>();
            using (StreamReader sr = new StreamReader(fIn.FullName)) {
                string line;
                while ((line = sr.ReadLine()) != null) {
                    input.Add(line);
                }
            }
            ret.inputLines = input;
            ret.ienum = ret.inputLines.GetEnumerator();
            return ret;
        }
        #endregion
    }
}
