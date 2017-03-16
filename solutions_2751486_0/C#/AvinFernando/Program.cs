using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO;

namespace GoogleCodeJam
{
    public class Program
    {
        public static ICodeJamProblem problem = new Round1CA();


        [STAThread]
        static void Main(string[] args)
        {
            OpenFileDialog dialog = new OpenFileDialog();
            dialog.InitialDirectory = @"C:\Users\afernando\Downloads\";
            dialog.Filter = "input files (*.in)|*.in|All files (*.*)|*.*";
            dialog.FilterIndex = 1;
            dialog.RestoreDirectory = true;
            if (dialog.ShowDialog() == DialogResult.OK)
            {
                var text = File.ReadAllText(dialog.FileName);

                SaveFileDialog saveDialog = new SaveFileDialog();

                saveDialog.Filter = "output files (*.out)|*.out|All files (*.*)|*.*";
                saveDialog.FilterIndex = 1;
                saveDialog.RestoreDirectory = true;
                saveDialog.InitialDirectory = @"C:\DevProjects\HLAProto\Main\Source\GoogleCodeJam\GoogleCodeJam";
                saveDialog.CheckFileExists = false;
                saveDialog.OverwritePrompt = false;

                if (saveDialog.ShowDialog() == DialogResult.OK)
                {
                    File.WriteAllText(saveDialog.FileName, problem.DoProblem(text));
                }

            }
        }
    }
}
