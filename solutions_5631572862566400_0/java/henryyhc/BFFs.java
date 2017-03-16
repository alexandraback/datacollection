import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

/**
 * Copyright 2016, Emory University
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *     http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/**
 * @author 	Henry(Yu-Hsin) Chen ({@code yu-hsin.chen@emory.edu})
 * @version	1.0
 * @since 	Apr 15, 2016
 */
public class BFFs {
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		
		int i, j, len, N, C = in.nextInt();
		int[] links; Set<Integer> visited = new HashSet<>();
		
		for(i = 1; i <= C; i++){
			len = 0; N = in.nextInt(); links = new int[N];
			for(j = 0; j < N; j++) links[j] = in.nextInt()-1;
			
			for(j = 0; j < N; j++){
				visited.clear();
				len = Math.max(len, traverse(links, j, j, j, visited));
			}
			System.out.printf("Case #%d: %d\n", i, len);
		}
		in.close();
	}
	
	public static int traverse(int[] links, int start, int prev, int from, Set<Integer> visited){
		int dest = links[from];
		if(visited.contains(from)) return -1;
		visited.add(from);
		
		if(visited.contains(dest)) {
			int size = visited.size();
			boolean front = false, back = false;
			if(dest == start) return size;
			else if(dest != start && dest == prev){
				for(int i = 0; i < links.length; i++){
					if(!front && links[i] == start && !visited.contains(i)){	front = true; size++; }
					if(!back && links[i] == from && !visited.contains(i)){ 	back = true; size++; }
				}
				return size;
			}
			else if(dest != start && dest != prev){
				for(int i = 0; i < links.length; i++){
					if(!front && links[i] == start && !visited.contains(i)){	front= true; size++; }
					if(!back && links[i] == from && !visited.contains(i)){ 	back = true; size++; }
				}
				return size-1;
			}
		}

		return traverse(links, start, from, dest, visited);
	}
}
