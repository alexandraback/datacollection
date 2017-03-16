using System;
using System.Collections.Generic;



 //ejp mysljylc kd kxveddknmc re jsicpdrysi
 //rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd
 //de kr kd eoya kw aej tysr re ujdr lkgc jv


 //Case #1: our language is impossible to understand
 //Case #2: there are twenty six factorial possibilities
 //Case #3: so it is okay if you want to just give up

namespace GCJ12_1
{
	class Program
	{
		public static void Main(string[] args)
		{
			string[] ein=new string[]{"ejp mysljylc kd kxveddknmc re jsicpdrysi",
				"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
				"de kr kd eoya kw aej tysr re ujdr lkgc jv"};
			string[] eout=new string[]{"our language is impossible to understand",
				"there are twenty six factorial possibilities",
				"so it is okay if you want to just give up"};
			SortedDictionary<char,char> d=new SortedDictionary<char, char>();
			for(int i=0;i<ein.Length;++i){
				for(int j=0;j<ein[i].Length;++j){
					d[ein[i][j]]=eout[i][j];
				}
			}
			
			//foreach(var a in d) Console.Write(a.Key+" "+a.Value+"\t");Console.WriteLine();
			
			d['y']='a';
			d['e']='o';
			d['q']='z';
			
			//foreach(var a in d) Console.Write(a.Key+" "+a.Value+"\t");Console.WriteLine();
			
			string sin="",sout="";
			foreach(var a in d){
				sin+=a.Key;
				sout+=a.Value;
			}
			string missin="",missout="";
			for(char ch='a';ch<='z';++ch){
				if(sin.IndexOf(ch)==-1)missin+=ch;
				if(sout.IndexOf(ch)==-1)missout+=ch;
			}
			
			if(missin.Length>1||missout.Length>1||missin.Length!=missout.Length){
				Console.WriteLine("Error!");
				return;
			}
			if(missin.Length==1){
				d[missin[0]]=missout[0];
			}
			
			//ready
			string str=Console.ReadLine();
			int n=int.Parse(str);
			
			for(int i=0;i<n;++i){
				str=Console.ReadLine();
				string ns="";
				for(int j=0;j<str.Length;++j){
					ns+=d[str[j]];
					
				}
				Console.WriteLine(String.Format("Case #{0}: {1}",i+1,ns));
			}
			
			int dummy=0;//debug?
		}
	}
}