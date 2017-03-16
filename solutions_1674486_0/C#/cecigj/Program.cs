using System;
using System.Collections.Generic;
using System.Text;
using System.Collections;
using System.IO;

namespace GoogleCodeJam2_Diamond
{
    class Program
    {
        internal static ArrayList nodes;
        static void Main(string[] args)
        {
            // Parseamos
            StreamReader sr = new StreamReader("input.txt");
            StreamWriter sw = new StreamWriter("ouput.txt");
            String line = sr.ReadLine();
            int numCases = int.Parse(line);
            for (int i=0;i<numCases;i++){
                line = sr.ReadLine();
                // Leemos el número de herencias
                int numHerit = int.Parse(line);
                nodes = new ArrayList();
                for(int j=1;j<=numHerit;j++){
                    nodes.Add(new Node(j));
                }
                // Parseamos las herencias
                for (int j = 1; j <= numHerit; j++)
                {
                    line = sr.ReadLine();
                    string[] caseStr = line.Split(' ');
                    int numFathers = int.Parse(caseStr[0]);
                    for(int k=1;k<=numFathers;k++){
                        ((Node)nodes[j-1]).AddFather( int.Parse(caseStr[k]));
                        ((Node)nodes[int.Parse(caseStr[k]) - 1]).AddSon(j);
                    }
                }
                // Ya tenemos los datos
                // Buscamos los candidatos
                ArrayList candidatesToRootPath = new ArrayList();
                ArrayList candidatesToLeafPath = new ArrayList();
                foreach (Node n in nodes)
                {
                    if(n.isCandidateToLeafPath())
                        candidatesToLeafPath.Add(n);
                    if(n.isCandidateToRootPath())
                        candidatesToRootPath.Add(n);
                }
                bool path = false;
                foreach(Node r in candidatesToRootPath){
                    foreach(Node l in candidatesToLeafPath)
                        if(r.pathsToNode(l.Value) > 1){
                            path = true;
                            break;
                        }
                    if (path)
                        break;
                }
                sw.WriteLine("Case #" + (i+1).ToString() + ": " + (path?"Yes":"No"));
            }
            sr.Close();
            sw.Close();

        }
    public class Node{

        int value;
        public int Value{
            get { return value; }
        }
        ArrayList sons;
        ArrayList fathers;
        public Node(int valueIn) { 
            value = valueIn;
            sons = new ArrayList();
            fathers = new ArrayList();
        }
        public void AddSon(int son)
        {
            sons.Add(son);
        }
        public void AddFather(int father)
        {
            fathers.Add(father);
        }
        public bool isCandidateToRootPath(){
            return (sons.Count>1)?true:false;
        }
        public bool isCandidateToLeafPath(){
            return (fathers.Count > 1) ? true : false;
        }
        public int pathsToNode(int node){
            int paths = 0;
            foreach (int son in sons)
            {
                if (node == son)
                    paths++;
                else
                    paths += ((Node)nodes[son-1]).pathsToNode(node);
            }
            return paths;
        }
    }

    };
}
