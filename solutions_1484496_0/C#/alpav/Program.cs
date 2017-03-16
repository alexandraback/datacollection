using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Diagnostics;
namespace t2012_1B_3{class Program {
    static string str(List<int> list){
        var ret=list.Select(e=>e.ToString()).Aggregate((cur,next)=>cur+" "+next);
        return ret;
    }
    static int sum(List<int> s){return s.Aggregate((cur,next)=>cur+next);}
    static bool eq(List<int> x,List<int> y){
        if(x.Count!=y.Count)return false;
        for(var i=-0;i<x.Count;i++){
            if(x[i]!=y[i])return false;
       }
        return true;
    }
    static List<List<int>> comb(List<int> s){
        var ret=new List<List<int>>();
        if(s.Count==0)return ret;
        var f=new List<int>();
        f.Add(s.First());
        ret.Add(f);
        var tail=comb(s.Skip(1).ToList());
        foreach(var t in tail){
            if(t.Count>0){
                ret.Add(t);
                ret.Add(f.Union(t).ToList());
            }
        }
        return ret;

    }
static void Main(string[] args){
    using(var rd=File.OpenText(@"..\..\in2.txt"))
    using(var w=File.CreateText(@"..\..\out2.txt")){
        var T=int.Parse(rd.ReadLine());
        for(var t=0;t<T;t++){
            var arr=rd.ReadLine().Split(' ').ToArray();
            int i=0;
            var S=int.Parse(arr[i++]);
            var a=arr.Skip(1).Select(e=>int.Parse(e)).ToList();
            var combs=comb(a);
            List<int> res1=null;
            List<int> res2=null;
            w.WriteLine("Case #"+t+":");
            var s1i=0;
            var s2i=0;
            foreach(var s1 in combs){
                foreach(var s2 in combs){
                    if(s1i!=s2i && !eq(s1,s2) && sum(s1)==sum(s2)){
                        res1=s1;
                        res2=s2;
                        w.WriteLine(str(s1));
                        Console.WriteLine(str(s1));
                        w.WriteLine(str(s2));
                        Console.WriteLine(str(s2));
                        break;
                    }
                    s2i++;
                }
                if(res1!=null)break;
                s1i++;
            }

           if(res1==null)
               w.WriteLine("Impossible");
        }
    }
    Console.ReadKey();
}
}}
