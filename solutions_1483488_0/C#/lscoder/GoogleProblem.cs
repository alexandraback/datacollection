using System;
using System.IO;

namespace LSCoder.CodeJam.ConsoleApp
{
    public abstract class GoogleProblem
    {
        #region Field

        private readonly string _fileName;
        private readonly StreamReader _streamReader;

        #endregion

        #region Constructors

        protected GoogleProblem(string fileName)
        {
            _fileName = fileName;
            _streamReader = new StreamReader(GetFilePath(fileName));
        }

        #endregion

        #region Private Methods

        private string GetFilePath(string fileName)
        {
            var filePath = Path.Combine(AppDomain.CurrentDomain.BaseDirectory, "..\\..\\..\\Resources");
            filePath = Path.Combine(filePath, fileName);

            if (!File.Exists(filePath))
            {
                throw new ApplicationException(string.Format("File [{0}] not found", fileName));
            }

            return filePath;
        }

        #endregion

        #region Protected Methods

        protected bool HasMoreLines()
        {
            return !_streamReader.EndOfStream;
        }

        protected string GetNextLine()
        {
            if(!HasMoreLines())
            {
                return string.Empty;
            }

            return _streamReader.ReadLine();
        }

        #endregion

        #region Public Methods

        public abstract void Execute();

        #endregion
    }
}
