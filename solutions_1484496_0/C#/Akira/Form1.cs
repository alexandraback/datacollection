using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace CodeJam2012Round1B3
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
                outputfile.WriteLine("Case #" + (numLine - 1).ToString() + ": " + Environment.NewLine
                   + GetSubSet(line));
            }

            return true;
        }

        private string GetSubSet(string line)
        {
            string retValue = string.Empty;
            string[] values = line.Split(' ');
            int cases = Convert.ToInt32(values[0]);
            Dictionary<long, string> subsets = new Dictionary<long, string>();

            for (int indexValue = 1; indexValue <= cases; indexValue++)
            {
                long currValue = Convert.ToInt64(values[indexValue]);

                if (subsets.ContainsKey(currValue))
                {
                    retValue =
                        subsets[currValue] + Environment.NewLine +
                        values[indexValue];
                    break;
                }
                else
                {
                    bool foundSubset = false;
                    foreach (long key in subsets.Keys)
                    {
                        if (subsets.ContainsKey(key + currValue))
                        {
                            retValue =
                                subsets[key] + " " + values[indexValue] + Environment.NewLine +
                                subsets[key + currValue];
                            foundSubset = true;
                            break;
                        }
                    }
                    if (foundSubset == true)
                    {
                        break;
                    }
                    else
                    {
                        Dictionary<long, string> addedSubsets = new Dictionary<long, string>();
                        foreach (long key in subsets.Keys)
                        {
                            addedSubsets.Add(key + currValue, subsets[key] + " " + values[indexValue]);
                        }
                        foreach(KeyValuePair<long, string> added in addedSubsets)
                        {
                            subsets.Add(added.Key, added.Value);
                        }
                        subsets.Add(currValue, values[indexValue]);
                    }
                }
            }

            if (string.IsNullOrEmpty(retValue))
            {
                retValue = "Impossible";
            }

            return retValue;
        }

        #endregion
    }
}
