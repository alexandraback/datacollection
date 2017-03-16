using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace CodeJam2012Round1B1
{
    public partial class Form1 : Form
    {
        #region Fields

        private int numCases = 0;

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
            }
            else
            {
                // Todo result
                outputfile.WriteLine("Case #" + (numLine - 1).ToString() + ": " +
                    GenerateResult(line));
            }

            return true;
        }

        private string GenerateResult(string line)
        {
            string retValue = string.Empty;
            string[] values = line.Split(' ');
            int participants = Convert.ToInt32(values[0]);
            List<int[]> scores = new List<int[]>();
            long totalScore = 0;

            for (int indexScore = 1; indexScore <= participants; indexScore++)
            {
                scores.Add(new int[]
                {
                    indexScore - 1,
                    Convert.ToInt32(values[indexScore])   
                });
                totalScore += scores[indexScore - 1][1];
            }
            int totalexcluded = 0;
            double average = totalScore * 2 / scores.Count;
            List<int> excludedValues = new List<int>();
            
            while (scores.Exists(
                searchValue => 
                    !excludedValues.Contains(searchValue[0]) &&
                    searchValue[1] >= average))
            {
                foreach (int[] excluded in scores.FindAll(
                    searchValue =>
                        !excludedValues.Contains(searchValue[0]) &&
                        searchValue[1] >= average))
                {
                    excludedValues.Add(excluded[0]);
                    totalexcluded += excluded[1];
                }
                average = 
                    (totalScore * 2 - totalexcluded) / 
                    (scores.Count - excludedValues.Count);
            }

            foreach (int[] score in scores)
            {
                double result = 0;

                if (!excludedValues.Exists(
                    findExcluded => findExcluded == score[0]))
                {
                    result = (average - score[1]) * 100 / totalScore;
                }
                retValue += (string.IsNullOrEmpty(retValue) ? string.Empty : " ") +
                    result.ToString("##0.000000").Replace(",", ".");
            }

            return retValue;
        }

        #endregion
    }
}
