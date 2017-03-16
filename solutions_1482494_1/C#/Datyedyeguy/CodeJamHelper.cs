using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

///////////////////////////////////////////////////////////////////////////////////////////////////

namespace CodeJam {
    /// <summary>
    /// This class will act as the interface between the input/output files and the specific program
    /// to handle the input from the Google Code Jam.  There are many methods created to retrieve the
    /// information necessary depending on the program along with handling the output so as to not
    /// have to worry about tracking case numbers, etc.
    /// </summary>
    public class CodeJamHelper : IDisposable {
        public string InputFileName {
            get;
            private set;
        }

        public string OutputFileName {
            get;
            private set;
        }

        public int TimeStart {
            get;
            private set;
        }

        public int TimeElapsed {
            get;
            private set;
        }

        private StreamReader mTextReader;
        private StreamWriter mTextWriter;
        private int mCaseNumber = 1;
        private bool mDisposed = false;

        /// <summary>
        /// Constructor
        /// </summary>
        /// <param name="inputFileName">The name of the file to read from.</param>
        public CodeJamHelper(string inputFileName) {
            InputFileName = inputFileName;

            if (!File.Exists(inputFileName)) {
                throw new FileNotFoundException();
            }

            OutputFileName = Path.ChangeExtension(InputFileName, ".out");
            mTextReader = new StreamReader(InputFileName);
            mTextWriter = new StreamWriter(OutputFileName);
        }

        public void Dispose () {
            Dispose(true);
            GC.SuppressFinalize(this);
        }

        protected void Dispose (bool disposing) {
            if (!mDisposed) {
                if (disposing) {
                    // Make sure that our files are written to & closed properly.

                    if (mTextReader != null) {
                        mTextReader.Dispose();
                    }

                    if (mTextWriter != null) {
                        mTextWriter.Dispose();
                    }
                }
            }

            mDisposed = true;
        }

        /// <summary>
        /// This takes in a value & writes it to the output file as the answer 
        /// to a case.  
        /// 
        /// NOTE: This increments the case number.
        /// </summary>
        /// <param name="value">The value to write out as the case answer.</param>
        public void WriteLine (string value) {
            WriteCaseIdentifier();
            mTextWriter.WriteLine("{0} ", value);
        }

        /// <summary>
        /// This takes in an array & writes it to the output file as the answer 
        /// to a case, with spaces in between each value.  
        /// 
        /// NOTE: This increments the case number.
        /// </summary>
        /// <param name="value">The strings to write out as the case answer.</param>
        public void WriteParts (string[] values) {
            WriteCaseIdentifier();

            for (int i = 0; i < values.Length; i++) {
                mTextWriter.Write("{0} ", values[i]);
            }

            mTextWriter.WriteLine();
        }

        /// <summary>
        /// This takes in a value & writes it to the output file as the answer 
        /// to a case.  
        /// 
        /// NOTE: This increments the case number.
        /// </summary>
        /// <param name="value">The value to write out as the case answer.</param>
        public void WriteObject (Object value) {
            WriteCaseIdentifier();
            mTextWriter.WriteLine("{0} ", value);
        }

        /// <summary>
        /// This takes in an array & writes it to the output file as the answer 
        /// to a case, with spaces in between each value.  
        /// 
        /// NOTE: This increments the case number.
        /// </summary>
        /// <param name="value">The strings to write out as the case answer.</param>
        public void WriteObjectArray (Object[] values) {
            WriteCaseIdentifier();

            for (int i = 0; i < values.Length; i++) {
                mTextWriter.Write("{0} ", values[i]);
            }

            mTextWriter.WriteLine();
        }

        /// <summary>
        /// This takes a value to write to the output file as the answer to a case.
        /// 
        /// NOTE: This increments the case number.
        /// </summary>
        /// <param name="value">The value to write out as the case answer.</param>
        public void WriteInt16 (short value) {
            WriteCaseIdentifier();
            mTextWriter.WriteLine("{0} ", value);
        }

        /// <summary>
        /// This takes in an array & writes it to the output file as the answer 
        /// to a case, with spaces in between each value.  
        /// 
        /// NOTE: This increments the case number.
        /// </summary>
        /// <param name="value">The ints to write out as the case answer.</param>
        public void WriteInt16Array (short[] values) {
            WriteCaseIdentifier();

            for (int i = 0; i < values.Length; i++) {
                mTextWriter.Write("{0} ", values[i]);
            }

            mTextWriter.WriteLine();
        }

        /// <summary>
        /// This takes a value to write to the output file as the answer to a case.
        /// 
        /// NOTE: This increments the case number.
        /// </summary>
        /// <param name="value">The value to write out as the case answer.</param>
        public void WriteInt32 (int value) {
            WriteCaseIdentifier();
            mTextWriter.WriteLine("{0} ", value);
        }

        /// <summary>
        /// This takes in an array & writes it to the output file as the answer 
        /// to a case, with spaces in between each value.  
        /// 
        /// NOTE: This increments the case number.
        /// </summary>
        /// <param name="value">The strings to write out as the case answer.</param>
        public void WriteInt32Array (int[] values) {
            WriteCaseIdentifier();

            for (int i = 0; i < values.Length; i++) {
                mTextWriter.Write("{0} ", values[i]);
            }

            mTextWriter.WriteLine();
        }

        /// <summary>
        /// This takes a value to write to the output file as the answer to a case.
        /// 
        /// NOTE: This increments the case number.
        /// </summary>
        /// <param name="value">The value to write out as the case answer.</param>
        public void WriteInt64 (long value) {
            WriteCaseIdentifier();
            mTextWriter.WriteLine("{0} ", value);
        }

        /// <summary>
        /// This takes in an array & writes it to the output file as the answer 
        /// to a case, with spaces in between each value.  
        /// 
        /// NOTE: This increments the case number.
        /// </summary>
        /// <param name="value">The strings to write out as the case answer.</param>
        public void WriteInt64Array (long[] values) {
            WriteCaseIdentifier();

            for (int i = 0; i < values.Length; i++) {
                mTextWriter.Write("{0} ", values[i]);
            }

            mTextWriter.WriteLine();
        }

        /// <summary>
        /// This takes a value to write to the output file as the answer to a case.
        /// 
        /// NOTE: This increments the case number.
        /// </summary>
        /// <param name="value">The value to write out as the case answer.</param>
        public void WriteDouble (double value) {
            WriteCaseIdentifier();
            mTextWriter.WriteLine("{0} ", value);
        }

        /// <summary>
        /// This takes in an array & writes it to the output file as the answer 
        /// to a case, with spaces in between each value.  
        /// 
        /// NOTE: This increments the case number.
        /// </summary>
        /// <param name="value">The strings to write out as the case answer.</param>
        public void WriteDoubleArray (double[] values) {
            WriteCaseIdentifier();

            for (int i = 0; i < values.Length; i++) {
                mTextWriter.Write("{0} ", values[i]);
            }

            mTextWriter.WriteLine();
        }

        /// <summary>
        /// Writes out the "Case #" string needed for each case, along with the current
        /// case number.  Used automatically by most 'Write*' functions.
        /// </summary>
        public void WriteCaseIdentifier () {
            mTextWriter.Write("Case #{0}: ", mCaseNumber);
            IncrementCaseNumber();
        }

        /// <summary>
        /// Increments the case number.
        /// </summary>
        public void IncrementCaseNumber () {
            mCaseNumber++;
        }

        /// <summary>
        /// Will read in the number of lines specified in count and return each element
        /// of each line as an array, each line getting its own array.
        /// 
        /// This will parse all values as shorts.
        /// </summary>
        /// <param name="count">The number of lines to read.</param>
        /// <returns>The values parsed from the file.</returns>
        public short[][] ReadInt16Arrays(int count) {
            short[][] lines = new short[count][];

            for (int i = 0; i < count; i++) {
                lines[i] = ReadInt16Array();
            }

            return lines;
        }

        /// <summary>
        /// Will read in the current line of the input file and parse the values
        /// into an array of values.
        /// 
        /// This will parse all values as shorts.
        /// </summary>
        /// <returns>The array of values.</returns>
        public short[] ReadInt16Array() {
            string[] parts = ReadParts();
            short[] values = new short[parts.Length];

            for (int i = 0; i < parts.Length; i++) {
                values[i] = short.Parse(parts[i]);
            }

            return values;
        }

        /// <summary>
        /// Will read in the number of lines specified in count and return each element
        /// of each line as an array, each line getting its own array.
        /// 
        /// This will parse all values as ints.
        /// </summary>
        /// <param name="count">The number of lines to read.</param>
        /// <returns>The values parsed from the file.</returns>
        public int[][] ReadInt32Arrays(int count) {
            int[][] lines = new int[count][];

            for (int i = 0; i < count; i++) {
                lines[i] = ReadInt32Array();
            }

            return lines;
        }

        /// <summary>
        /// Will read in the current line of the input file and parse the values
        /// into an array of values.
        /// 
        /// This will parse all values as ints.
        /// </summary>
        /// <returns>The array of values.</returns>
        public int[] ReadInt32Array() {
            string[] parts = ReadParts();
            int[] values = new int[parts.Length];

            for (int i = 0; i < parts.Length; i++) {
                values[i] = int.Parse(parts[i]);
            }

            return values;
        }

        /// <summary>
        /// Will read in the number of lines specified in count and return each element
        /// of each line as an array, each line getting its own array.
        /// 
        /// This will parse all values as longs.
        /// </summary>
        /// <param name="count">The number of lines to read.</param>
        /// <returns>The values parsed from the file.</returns>
        public long[][] ReadInt64Arrays(int count) {
            long[][] lines = new long[count][];

            for (int i = 0; i < count; i++) {
                lines[i] = ReadInt64Array();
            }

            return lines;
        }

        /// <summary>
        /// Will read in the current line of the input file and parse the values
        /// into an array of values.
        /// 
        /// This will parse all values as longs.
        /// </summary>
        /// <returns>The array of values.</returns>
        public long[] ReadInt64Array() {
            string[] parts = ReadParts();
            long[] values = new long[parts.Length];

            for (int i = 0; i < parts.Length; i++) {
                values[i] = long.Parse(parts[i]);
            }

            return values;
        }

        /// <summary>
        /// Will read in the number of lines specified in count and return each element
        /// of each line as an array, each line getting its own array.
        /// 
        /// This will parse all values as doubles.
        /// </summary>
        /// <param name="count">The number of lines to read.</param>
        /// <returns>The values parsed from the file.</returns>
        public double[][] ReadDoubleArrays(int count) {
            double[][] lines = new double[count][];

            for (int i = 0; i < count; i++) {
                lines[i] = ReadDoubleArray();
            }

            return lines;
        }

        /// <summary>
        /// Will read in the current line of the input file and parse the values
        /// into an array of values.
        /// 
        /// This will parse all values as longs.
        /// </summary>
        /// <returns>The array of values.</returns>
        public double[] ReadDoubleArray() {
            string[] parts = ReadParts();
            double[] values = new double[parts.Length];

            for (int i = 0; i < parts.Length; i++) {
                values[i] = double.Parse(parts[i]);
            }

            return values;
        }

        /// <summary>
        /// Reads the next line from the input file.
        /// </summary>
        /// <returns>The next line.</returns>
        public string ReadLine() {
            return mTextReader.ReadLine();
        }

        /// <summary>
        /// Takes a line from the input file and returns an array of strings of the values
        /// of that line, delimeted by spaces.
        /// <seealso cref="ReadLine()"/>
        /// </summary>
        /// <returns>The array of strings.</returns>
        public string[] ReadParts () {
            return ReadLine().Split(' ');
        }

        /// <summary>
        /// Reads in a number of lines from the input file and returns them as an array
        /// of strings.
        /// <seealso cref="ReadLine()"/>
        /// </summary>
        /// <param name="count">The number of lines to read.</param>
        /// <returns>The array of strings.</returns>
        public string[] ReadLines(int count) {
            string[] lines = new string[count];

            for (int i = 0; i < count; i++) {
                lines[i] = ReadLine();
            }

            return lines;
        }

        /// <summary>
        /// Returns the next line of the input file as a short.
        /// </summary>
        /// <returns>A short.</returns>
        public short ReadLineInt16() {
            return short.Parse(ReadLine());
        }

        /// <summary>
        /// Returns the next line of the input file as an int.
        /// </summary>
        /// <returns>An int.</returns>
        public int ReadLineInt32() {
            return int.Parse(ReadLine());
        }

        /// <summary>
        /// Returns the next line of the input file as a long.
        /// </summary>
        /// <returns>A long.</returns>
        public long ReadLineInt64() {
            return long.Parse(ReadLine());
        }

        /// <summary>
        /// Returns the next line of the input file as a double.
        /// </summary>
        /// <returns>A double.</returns>
        public double ReadLineDouble() {
            return double.Parse(ReadLine());
        }
    }
}
