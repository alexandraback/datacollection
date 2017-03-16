import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

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
public class TheLastWord {
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		
		List<Character> list = new ArrayList<>();
		int i, C = in.nextInt(); in.nextLine();
		for(i = 1; i <= C; i++){
			list.clear();
			for(char c : in.nextLine().toCharArray()){
				if(list.isEmpty()) list.add(c);
				else{
					if(c >= list.get(0)) 
						list.add(0, c);
					else list.add(c);
				}
			}
			System.out.print("Case #" + i + ": ");
			for(char c : list) System.out.print(c);
			System.out.println();
		}
		
		in.close();
	}
}
