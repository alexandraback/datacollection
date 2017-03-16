using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace CodeJam2012Round1C1
{
    public partial class Form1 : Form
    {
        #region Fields

        private int numCases = 0;
        private int currCase = 1;
        private int numClasses = 0;
        private Dictionary<int, List<int>> diagram = new Dictionary<int, List<int>>();
        List<int[]> inheritances = new List<int[]>();

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
                    currCase = 1;
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
                if (numClasses == 0)
                {
                    numClasses = Convert.ToInt32(line);
                    diagram = new Dictionary<int,List<int>>();
                    inheritances = new List<int[]>();
                }
                else
                {
                    diagram.Add(diagram.Count + 1, new List<int>());

                    string[] values = line.Split(' ');

                    if (values[0] != "0")
                    {
                        for (int indexValue = 1; indexValue < values.Length; indexValue++)
                        {
                            diagram[diagram.Count].Add(
                                Convert.ToInt32(values[indexValue]));
                        }
                    }
                    if (diagram.Count == numClasses)
                    {
                        string result = ProcessResult(0, 0);
                        // Todo result
                        outputfile.WriteLine("Case #" + currCase.ToString() + ": " +
                            (string.IsNullOrEmpty(result) ? "No" : result));
                        currCase++;
                        numClasses = 0;
                    }
                }
            }

            return true;
        }

        private string ProcessResult(int startdiagram, int classid)
        {
            string retValue = string.Empty;
            foreach (KeyValuePair<int, List<int>> dclass in diagram.Where(
                searchDiagram =>
                    (searchDiagram.Value.Count > 1 &&
                     classid == 0) ||
                    (searchDiagram.Key == classid &&
                     searchDiagram.Value.Count >= 1)))
            {
                if (classid == 0)
                {
                    startdiagram = dclass.Key;
                }
                foreach (int parent in dclass.Value)
                {
                    if (inheritances.Exists(
                        findValue =>
                            findValue[0] == startdiagram &&
                            findValue[1] == parent))
                    {
                        return "Yes";
                    }
                    else
                    {
                        inheritances.Add(
                            new int[]
                            {
                                startdiagram,
                                parent
                            });

                        retValue = ProcessResult(
                            startdiagram,
                            parent);

                        if (!string.IsNullOrEmpty(retValue))
                        {
                            return retValue;
                        }
                    }
                }
            }

            return retValue;
        }

        #endregion
    }
}
