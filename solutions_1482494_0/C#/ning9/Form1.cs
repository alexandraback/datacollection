using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO;

namespace WindowsFormsApplication2
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            StreamReader infile = new System.IO.StreamReader("B-small-attempt0.in");
            StreamWriter outfile = new System.IO.StreamWriter("output.txt");
            int testCases = Int32.Parse(infile.ReadLine());
            

            for (int caseNo = 1; caseNo <= testCases; caseNo++) // note this is 1-based
            {
                int levelCases = Int32.Parse(infile.ReadLine());

                int[] a = new int[levelCases];
                int[] b = new int[levelCases];

                for (int levelNo = 0; levelNo < levelCases; levelNo++) // note this is 1-based
                {
                    string[] data = (infile.ReadLine()).Split(new char[] { ' ' }, StringSplitOptions.None);
                    a[levelNo] = Convert.ToInt32(data[0]);
                    b[levelNo] = Convert.ToInt32(data[1]);
                }

                int retValue = findtimes(levelCases, a, b);

                if(retValue != -1)
                    outfile.WriteLine(String.Format("Case #{0}: {1}", caseNo, retValue));
                else
                    outfile.WriteLine(String.Format("Case #{0}: Too Bad", caseNo));
            }
            infile.Close();
            outfile.Flush();
            outfile.Close();

        }

        public int findtimes(int N, int[] a, int[] b)
        {
	        int[] s = new int [N]; //star 0으로 초기화
	        for(int i=0; i< N; i++)
		        s[i] = 0;

	        int earnStar = 0;
	        int cnt = 0;
	        int maxNum;
	        int idx;
	        bool chgchk;

	        while(true){
		        chgchk = false;
		        for(int i=0;i < N; i++)
		        {
			        if(b[i] <= earnStar && s[i] < 2)
			        {
				        earnStar+=(2 - s[i]);
                        cnt++;
				        s[i] = 2;
				        chgchk = true;
			        }
		        }

                if (chgchk == false)
                {
                    idx = -1;
                    maxNum = -1;
                    for (int i = 0; i < N; i++)
                    {
                        if (a[i] <= earnStar && s[i] == 0 && maxNum < b[i])
                        {
                            idx = i;
                            maxNum = b[i];
                        }
                    }

                    if (idx != -1)
                    {
                        earnStar += 1;
                        cnt++;
                        s[idx] = 1;
                        chgchk = true;
                    }
                }

		        if(chgchk == false)
			        return -1;

		        
		        if(earnStar == N*2)
			        return cnt;

	        }
        }
    }
}
