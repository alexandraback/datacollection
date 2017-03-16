using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace CodeJam2013Qualification1
{
    public partial class Form1 : Form
    {
        #region Constants

        private static string XWON = "X won";
        private static string OWON = "O won";
        private static string DRAW = "Draw";
        private static string INCOMPLETE = "Game has not completed";

        private static char X = 'X';
        private static char O = 'O';
        private static char EMPTY = '.';
        private static char T = 'T';

        #endregion

        #region Fields

        private int numCases = 0;
        private static List<string> lines = new List<string>();
        private int currentCase = 1;
        private int contline = 0;

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
                contline = 0;
                lines = new List<string>();
            }
            else
            {
                if (!string.IsNullOrEmpty(line))
                {
                    lines.Add(line);
                    contline++;
                    if (contline >= 4)
                    {
                        // Todo result
                        outputfile.WriteLine("Case #" + (currentCase).ToString() + ": " + ProcessCase(lines));
                        lines = new List<string>();
                        currentCase++;
                        contline = 0;
                    }
                }
            }

            return true;
        }

        public string ProcessCase(List<string> lines)
        {
            List<string> rows = new List<string>();
            List<string> diagonals = new List<string>();

            rows.Add(string.Concat(lines[0][0],lines[1][0],lines[2][0],lines[3][0]));
            rows.Add(string.Concat(lines[0][1],lines[1][1],lines[2][1],lines[3][1]));
            rows.Add(string.Concat(lines[0][2],lines[1][2],lines[2][2],lines[3][2]));
            rows.Add(string.Concat(lines[0][3],lines[1][3],lines[2][3],lines[3][3]));

            diagonals.Add(string.Concat(lines[0][0],lines[1][1],lines[2][2],lines[3][3]));
            diagonals.Add(string.Concat(lines[0][3],lines[1][2],lines[2][1],lines[3][0]));

            if (lines.Exists(line => !line.Contains(EMPTY) && !line.Contains(O)) ||
                rows.Exists(line => !line.Contains(EMPTY) && !line.Contains(O)) ||
                diagonals.Exists(line => !line.Contains(EMPTY) && !line.Contains(O)))
            {
                return XWON;
            }
            else if (
                lines.Exists(line => !line.Contains(EMPTY) && !line.Contains(X)) ||
                rows.Exists(line => !line.Contains(EMPTY) && !line.Contains(X)) ||
                diagonals.Exists(line => !line.Contains(EMPTY) && !line.Contains(X)))
            {
                return OWON;
            }
            else if(
                !lines.Exists(line => line.Contains(EMPTY)))
            {
                return DRAW;
            }


            return INCOMPLETE;
        }

        #endregion
    }
}
