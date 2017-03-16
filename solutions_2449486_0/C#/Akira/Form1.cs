using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace CodeJam2013Qualification2
{
    public partial class Form1 : Form
    {
        #region Constants

        

        #endregion

        #region Fields

        private int numCases = 0;
        private static List<string> lines = new List<string>();
        private int currentCase = 1;
        private int numlines = 0;
        private int numColumns = 0;

        #endregion

        #region Constructor

        public Form1()
        {
            InitializeComponent();
        }

        #endregion

        #region Events

        #region Button Events

        /// <summary>
        /// Event occurs when the button open file is clicked
        /// </summary>
        /// <param name="sender">Sender of the event (btnOpenFile)</param>
        /// <param name="e">Click parameters</param>
        private void btnOpenFile_Click(object sender, EventArgs e)
        {
            if (ofdOpenFile.ShowDialog() == System.Windows.Forms.DialogResult.OK)
            {
                txtInputFile.Text = ofdOpenFile.FileName;
                txtOutputFile.Text = txtInputFile.Text.Replace("in", "out");
            }
            else
            {
                txtInputFile.Text = string.Empty;
            }
        }

        /// <summary>
        /// Event occurs when the button save file is clicked
        /// </summary>
        /// <param name="sender">Sender of the event (btnSaveFile)</param>
        /// <param name="e">Click parameters</param>
        private void btnSaveFile_Click(object sender, EventArgs e)
        {
            if (sfdSaveFile.ShowDialog() == System.Windows.Forms.DialogResult.OK)
            {
                txtOutputFile.Text = sfdSaveFile.FileName;
            }
            else
            {
                txtOutputFile.Text = string.Empty;
            }
        }

        /// <summary>
        /// Event occurs when the button generate is clicked
        /// </summary>
        /// <param name="sender">Sender of the event (btnGenerate)</param>
        /// <param name="e">Click parameters</param>
        private void btnGenerate_Click(object sender, EventArgs e)
        {
            if (!string.IsNullOrEmpty(txtInputFile.Text) &&
                !string.IsNullOrEmpty(txtOutputFile.Text))
            {
                if (bckProcess.IsBusy != true)
                {
                    pbrStatus.Value = 0;
                    EnableDisableControls(false);
                    bckProcess.RunWorkerAsync();
                }
            }
        }

        /// <summary>
        /// Event occurs when the button cancel is clicked
        /// </summary>
        /// <param name="sender">Sender of the event (btnCancel)</param>
        /// <param name="e">Click parameters</param>
        private void btnCancel_Click(object sender, EventArgs e)
        {
            if (bckProcess.WorkerSupportsCancellation == true)
            {
                bckProcess.CancelAsync();
            }
        }

        #endregion

        #region BackgroundWorker Events

        /// <summary>
        /// 
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void bckProcess_DoWork(object sender, DoWorkEventArgs e)
        {
            BackgroundWorker worker = (BackgroundWorker)sender;
            int currentLine = 1;
            using (System.IO.StreamWriter outputfile = new System.IO.StreamWriter(txtOutputFile.Text))
            {
                string[] lines = System.IO.File.ReadAllLines(txtInputFile.Text);
                foreach (string line in lines)
                {
                    if (worker.CancellationPending == true)
                    {
                        e.Cancel = true;
                        break;
                    }
                    if (ProcessLine(line, currentLine, outputfile) == false)
                    {
                        break;
                    }
                    worker.ReportProgress(currentLine * 100 / lines.Length);
                    currentLine++;
                }
                outputfile.Close();
            }
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void bckProcess_ProgressChanged(object sender, ProgressChangedEventArgs e)
        {
            pbrStatus.Value = e.ProgressPercentage;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void bckProcess_RunWorkerCompleted(object sender, RunWorkerCompletedEventArgs e)
        {
            if (e.Cancelled == true)
            {
                MessageBox.Show("Process Cancelled!");
            }
            else if (e.Error != null)
            {
                MessageBox.Show("Error: " + e.Error.Message);
            }
            else
            {
                MessageBox.Show("Process Complete!");
            }
            EnableDisableControls(true);
        }

        #endregion

        #endregion

        #region Methods

        /// <summary>
        /// Disable/Enable the controls of the form, except of button Cancel
        /// </summary>
        /// <param name="enabled"></param>
        private void EnableDisableControls(bool enabled)
        {
            foreach (Control control in this.Controls)
            {
                if (control.Name == "btnCancel")
                {
                    control.Enabled = !enabled;
                }
                else
                {
                    control.Enabled = enabled;
                }
            }
        }

        /// <summary>
        /// Process the current line
        /// </summary>
        /// <param name="line">Line which is processing</param>
        /// <param name="numLine">Number of the line</param>
        /// <param name="outputfile">Stream write of the output file</param>
        /// <returns>Returns if the line is processed</returns>
        protected bool ProcessLine(string line,
                                   int numLine,
                                   System.IO.StreamWriter outputfile)
        {
            if (numLine == 1)
            {
                numCases = Convert.ToInt32(line);
                currentCase = 1;
                numlines = 0;
                numColumns = 0;
                lines = new List<string>();
            }
            else
            {
                if (numlines == 0 && numColumns == 0)
                {
                    string[] values = line.Split(new char[] { ' ' });
                    numlines = Convert.ToInt32(values[0]);
                    numColumns = Convert.ToInt32(values[1]);
                    lines = new List<string>();
                }
                else
                {
                    lines.Add(line);
                    if (lines.Count >= numlines)
                    {
                        //outputfile.WriteLine(
                        //    string.Join(Environment.NewLine, lines));
                        // Todo result
                        outputfile.WriteLine("Case #" + (currentCase).ToString() + ": " + ProcessCase(lines));
                        currentCase++;
                        numlines = 0;
                        numColumns = 0;
                    }
                }
            }

            return true;
        }

        public string ProcessCase(List<string> lines)
        {
            List<List<int>> grass = new List<List<int>>();
            foreach (string line in lines)
            {
                grass.Add(new List<int>(
                    line.Split(new char[] { ' ' }).Select<string, int>(
                        strValue => Convert.ToInt32(strValue))));
            }

            for (int indexRow = 0; indexRow < lines.Count; indexRow++)
            {
                for (int indexColumn = 0; indexColumn < numColumns; indexColumn++)
                {
                    List<int> columnValues = grass.Select(
                        row => row[indexColumn]).ToList();
                    List<int> rowValues = grass[indexRow];
                    if (rowValues.Exists(
                        rowValue => rowValue > grass[indexRow][indexColumn]) &&
                        columnValues.Exists(
                        columnValue => columnValue > grass[indexRow][indexColumn]))
                    {
                        return "NO";
                    }
                }
            }
            return "YES";  
        }

        #endregion
    }
}
