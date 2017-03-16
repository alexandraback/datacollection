package com.example.p1;

import java.util.Scanner;

public class qbr1 {
		
	    static Integer E,R,N,T;
	    static int[][] maximum;
	    static int[] v;
	    static Scanner cin;
	    
	    public static Integer dp(Integer st, Integer ed, Integer begin, Integer end){
	        if(begin >= E) begin = E;
	        if(end < 0) end = 0;
	        if(st > ed) return 0;
	        if(st == ed)
	        {
	            if(begin >= end)
	                return (begin-end) * v[st];
	            else
	                return 0;
	        }
	        else
	        {
	            int findmax = maximum[st][ed];
	            Integer minvalue = 0;
	            if(R * (ed - findmax) < end)
	            {
	                minvalue = end - R * (ed - findmax);
	            }
	            Integer maxvalue = E;
	            if(begin + (findmax - st) < E)
	            {
	                maxvalue = begin + (findmax - st);
	            }
	            Integer use = maxvalue - minvalue;
	            return use * v[findmax] + dp(st,findmax-1,begin,maxvalue-R) + dp(findmax + 1, ed, minvalue + R, end);
	        }
	    }

	    public static void main(String[] arg)
	    {
	    	cin = new Scanner(System.in);
	    	maximum = new int[10000][];
	    	for(int i=0;i<10000;i++)
	    		maximum[i] = new int[10000];
	    	v = new int[10000];
	    	T = cin.nextInt();
	        for(int c=1;c<=T;c++)
	        {
	        	E = cin.nextInt();
	        	R = cin.nextInt();
	        	N = cin.nextInt();
	            for(int i=0;i<N;i++)
	                v[i] = cin.nextInt();
	            for(int i=0;i<N;i++)
	            {
	                maximum[i][i] = i;
	            }
	            for(int i=0;i<N;i++)
	            {
	                for(int j=1;i+j<N;j++)
	                {
	                    if(v[maximum[i][i+j-1]] < v[i+j])
	                        maximum[i][i+j] = i+j;
	                    else
	                        maximum[i][i+j] = maximum[i][i+j-1];
	                }
	            }
	            System.out.println("Case #"+c+": "+dp(0,N-1,E,0));
	        }
	    }
	}