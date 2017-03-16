   import java.util.*;
   import java.io.*;
   import java.math.*;
   public class tow{
      static int current = 0;
      public static void main(String[] args) throws Exception
      {
         BufferedReader f = new BufferedReader(new FileReader("tow.in"));
         PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("tow.out")));
         int cases = Integer.parseInt(f.readLine());
         for(int cas = 1; cas<=cases; cas++){
            int n = Integer.parseInt(f.readLine());
            T[] ar = new T[n];
            LinkedList<T> todo = new LinkedList<T>();
            current = 0;
            int count = 0;
            for(int i = 0; i<n; i++){
               StringTokenizer st = new StringTokenizer(f.readLine());
               ar[i] = new T(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()), 0);
               todo.add(ar[i]);
            }
            boolean fail = false;
            while(!todo.isEmpty()){
               T t = todo.peek();
               for(T e:todo){
                  if(e.prio()<=t.prio())
                     if(e.prio() != t.prio())
                        t = e;
                     else if(e.next()>t.next())
                        t = e;
                     else if(e.next()==t.next()){
                        if(e.nextp()>t.nextp())
                           t = e;}
                     else if(e.e>t.e)
                        t = e;
               }
               if(t.get()>current){
                  fail = true;
                  break;}
               if(current>=t.e){
                  current+=2-t.f;
                  count++;
                  todo.remove(t);
               }
               else if (t.f==0)
               {
                  current+=1-t.f;
                  t.f = 1;
                  count++;
               }
            }
            if(fail)
               out.println("Case #"+cas+": Too Bad");
            else
               out.println("Case #"+cas+": "+count);
         }      
         out.close();
         System.exit(0);
         
      }
      static class T implements Comparable<T>{
         public int d, e, f;
         public T(int a, int b, int c){
            d = a; e = b; f = c;}
         public int get(){
            if(f==0){
               if(e<=current)
                  return e;
               return d;
            }
            return e;
         }
         public int nextp(){
            if(f==0){
               if(e<=current)
                  return 2;
               return 1;
            }
            return 1;
         }
         public int next(){
            if(f==0)
               if(e<=current)
                  return 2;
            return 1;
         }
         public int prio(){
            if(get()<=current)
               return current-get();
            return current+get();
         }
         public int compareTo(T t){
            return prio()-t.prio();
         }
         public String toString(){
            return d+" "+e+" "+f+" "+get()+" "+prio();
         }
      }
   }