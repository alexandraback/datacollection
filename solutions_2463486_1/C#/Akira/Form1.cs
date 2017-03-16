using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Numerics;

namespace CodeJam2013Qualification3
{
    public partial class Form1 : Form
    {
        #region Fields

        private int numCases = 0;

        //private SortedDictionary<BigInteger, BigInteger> fairSquares = new SortedDictionary<BigInteger, BigInteger>();
        private List<BigInteger> fairSquares = new List<BigInteger>();

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
                if (!string.IsNullOrEmpty(line))
                {
                    // Todo result
                    outputfile.WriteLine("Case #" + (numLine - 1).ToString() + ": " + ProcessCase(line));
                }
            }

            return true;
        }

        public string ProcessCase(string line)
        {
            string[] values = line.Split(new char[] { ' ' });

            BigInteger limitInf = BigInteger.Parse(values[0]);
            BigInteger liminsup = BigInteger.Parse(values[1]);

            return fairSquares.Where(
                value => value >= limitInf && value <= liminsup).Count().ToString();
        }

        #endregion

        private void btnGenerateList_Click(object sender, EventArgs e)
        {

            //DateTime startProcess = DateTime.Now;

            //fairSquares = new SortedDictionary<BigInteger, BigInteger>();

            //fairSquares.Add(1, 1);
            //fairSquares.Add(2, 4);
            //fairSquares.Add(3, 9);

            fairSquares = new List<BigInteger>();

            fairSquares.Add(1);
            fairSquares.Add(4);
            fairSquares.Add(9);

            BigInteger value = 0;

            for (int i = 2; i <= (Convert.ToInt32(txtLimit.Text) / 2); i++)
            {
                if (i % 2 == 0)
                {
                    value = BigInteger.Parse("2" + new string('0', i - 2) + "2");

                    //fairSquares.Add(value, BigInteger.Pow(value, 2));
                    fairSquares.Add(BigInteger.Pow(value, 2));

                    int x = (i - 2) / 2;

                    if (x > 0)
                    {
                        for (int p = 0; p < Math.Pow(2, x); p++)
                        {
                            string strValue = "1" + Convert.ToString(p, 2).PadLeft(x, '0');

                            if (strValue.Where(
                                charValue => charValue == '1').Count() <= 4)
                            {
                                value = BigInteger.Parse(strValue + new string(strValue.Reverse().ToArray()));

                                //fairSquares.Add(value, BigInteger.Pow(value, 2));
                                fairSquares.Add(BigInteger.Pow(value, 2));
                            }
                        }
                    }
                    else
                    {
                        //fairSquares.Add(11, 121);
                        fairSquares.Add(121);
                    }
                }
                else
                {
                    value = BigInteger.Parse("2" + new string('0', (i - 2) / 2) + "0" + new string('0', (i - 2) / 2) + "2");

                    //fairSquares.Add(value, BigInteger.Pow(value, 2));
                    fairSquares.Add(BigInteger.Pow(value, 2));

                    value = BigInteger.Parse("2" + new string('0', (i - 2) / 2) + "1" + new string('0', (i - 2) / 2) + "2");

                    //fairSquares.Add(value, BigInteger.Pow(value, 2));
                    fairSquares.Add(BigInteger.Pow(value, 2));

                    int x = (i - 2) / 2;

                    if (x > 0)
                    {
                        for (int p = 0; p < Math.Pow(2, x); p++)
                        {
                            string strValue = "1" + Convert.ToString(p, 2).PadLeft(x, '0');

                            for (int center = 0; center < 3; center++)
                            {
                                if ((strValue.Where(
                                 charValue => charValue == '1').Count() * 2) + 
                                    ((int)Math.Pow(center,2))< 10)
                                {
                                    value = BigInteger.Parse(strValue + center.ToString() + new string(strValue.Reverse().ToArray()));

                                    //fairSquares.Add(value, BigInteger.Pow(value, 2));
                                    fairSquares.Add(BigInteger.Pow(value, 2));
                                } 
                            }
                        }
                    }
                    else
                    {
                        //fairSquares.Add(121, 14641);
                        //fairSquares.Add(111, 12321);
                        //fairSquares.Add(101, 10201);
                        fairSquares.Add(10201);
                        fairSquares.Add(12321);
                        fairSquares.Add(14641);
                    }
                }
            }

            //System.IO.File.WriteAllLines(
            //    txtOutputFile.Text,
            //    new string[]
            //    {
            //        startProcess.ToString()
            //    });

            //System.IO.File.AppendAllLines(
            //    txtOutputFile.Text,
            //    fairSquares.Select(
            //        keyvalue => keyvalue.Key + "=>" + keyvalue.Value));

            //System.IO.File.AppendAllLines(
            //    txtOutputFile.Text,
            //    new string[]
            //    {
            //        DateTime.Now.ToString()
            //    });
        }
    }
}
