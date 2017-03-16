using System;
using System.Linq;
using System.Collections;
using System.Collections.Generic;

namespace Osmos
{
	class MainClass
	{
		public static long calcops( long osmos, List<int> remaining )
		{
			int ops = 0;
			for ( int j=0; j < remaining.Count; j++ ) {
				if ( osmos == 1 ) {
					ops = remaining.Count;
					break;
				}
				int next = remaining[j];
				if ( next < osmos ) {
					osmos += next;
				} else {
					int times = 0;
					while ( osmos <= next ) {
						times++;
						osmos += osmos - 1;
					}
					
					osmos += next;
					
					long remainingops = calcops( osmos, remaining.Skip(j+1).ToList() );
						
					if ( times + remainingops >= remaining.Count - j ) {
						ops += remaining.Count - j;
						break;
					} else {
						ops += times;
					}
				}
			}
			return ops;
		}
		public static void Main (string[] args)
		{
			int cases = int.Parse( Console.ReadLine() );
			
			for ( int i=0; i < cases; i++ ) {
				List<int> l1 = Console.ReadLine().Split(' ').Select( s => int.Parse(s) ).ToList();
				List<int> l2 = Console.ReadLine().Split(' ').Select( s => int.Parse(s) ).ToList();
				l2.Sort();
				long osmos = l1[0];
				int length = l1[1];
				long ops = calcops( osmos, l2 );
//				for ( int j=0; j < l2.Count; j++ ) {
//					if ( osmos == 1 ) {
//						ops = l2.Count;
//						break;
//					}
//					int next = l2[j];
//					if ( next < osmos ) {
//						osmos += next;
//					} else {
//						int times = 0;
//						while ( osmos <= next ) {
//							times++;
//							osmos += osmos - 1;
//						}
//							
//						if ( times >= l2.Count - j ) {
//							ops += l2.Count - j;
//							break;
//						} else {
//							ops += times;
//						}
//					}
//				}
				Console.WriteLine( "Case #{0}: {1}", i+1, ops );
			}
		}
	}
}
