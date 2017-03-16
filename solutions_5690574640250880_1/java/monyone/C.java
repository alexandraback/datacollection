import java.util.HashSet;
import java.util.LinkedList;
import java.util.Scanner;
import java.util.Set;

public class C {

	public static int draw(int s_x, int s_y, int C, int R, int num,
			String target, String[][] map, boolean flag) {

		int count = 0;
		if (flag) {
			LOOP:
			for (int y = s_y; y < R; y++) {
				for (int x = s_x; x < C; x++) {
					if (count >= num) {
						break LOOP;
					}

					map[y][x] = target;

					count++;
				}
			}
		} else {
			LOOP:
			for (int x = s_x; x < C; x++) {
				for (int y = s_y; y < R; y++) {
					if (count >= num) {
						break LOOP;
					}

					map[y][x] = target;

					count++;
				}
			}
		}

		return count;
	}
	
	public static String[][] init_map(final int R, final int C){
		return clear_map(R, C, new String[R][C]);
	}
	
	public static String[][] clear_map(final int R, final int C, String[][] map){
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				map[i][j] = ".";
			}
		}
		map[R - 1][C - 1] = "c";
		
		return map;
	}

	public static boolean solve(final int R, final int offset_R, final int C, final int offset_C, final int M, String[][] map){
		final int real_R = R - offset_R;
		final int real_C = C - offset_C;
		
		final int size = real_R * real_C;
		final int global_min = Math.min(R, C);
		
		if(M == 0){
			return true;
		}else if (global_min == 1) {
			// ok!
			draw(0, 0, C, R, M, "*", map, true);
			return true;
		} else if(size - 1 == M){
			// ok!
			draw(offset_C, offset_R, C, R, M, "*", map, true);
			return true;
		} else if(M % real_R != real_R - 1 && (real_C - (M / real_R) > 2) || (size - M == 2 * real_R)){
			draw(offset_C, offset_R, C, R, M, "*", map, false);
			return true;
		} else if(M % real_C != real_C - 1 && (real_R - (M / real_C) > 2) || (size - M == 2 * real_C)){
			draw(offset_C, offset_R, C, R, M, "*", map, true);
			return true;
		} else{
			final int real_R_ok = offset_R + Math.max(0, real_R - 2);
			final int real_C_ok = offset_C + Math.max(0, real_C - 2);

			final int always_rest = M - draw(offset_C, offset_R, real_C_ok, real_R_ok, M, "*", map, true);

			if(always_rest <= 0){
				return true;
			}else if(always_rest % 2 != 0){
				return false;
			}
			
			final int right_rest = always_rest - draw(real_C_ok, offset_R, C, real_R_ok, always_rest, "*", map, true);

			if (right_rest <= 0) {
				return true;
			}
			
			final int bottom_rest = right_rest - draw(offset_C, real_R_ok, real_C_ok, R, right_rest, "*", map, false);

			if (bottom_rest > 0) {
				return false;
			}else{
				return true;
			}
		}
	}
	
	public static void show_map(final int R, final int C, String[][] map){
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				System.out.print(map[i][j]);
			}
			System.out.println();
		}
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		
		final int T = sc.nextInt();

		for (int tc = 0; tc < T; tc++) {
			final int tc_index = tc + 1;

			final int R = sc.nextInt();
			final int C = sc.nextInt();
			final int M = sc.nextInt();
			
			String[][] map = init_map(R, C);
			boolean ok = solve(R, 0, C, 0, M, map);
			LOOP:
			for(int offset_R = 0; offset_R < R - 1; offset_R++){
				for(int offset_C = 0; offset_C < C - 1; offset_C++){
					if(ok){
						break LOOP;
					}
					
					final int n_M = M - (C * offset_R) - (R * offset_C) + (offset_R * offset_C);
					if(n_M < 0){
						continue;
					}
					
					//System.out.println(M + " " + (R - offset_R) + " " + (C - offset_C) + " " + n_M);
					clear_map(R, C, map);
					draw(0, 0, C, offset_R, R * C, "*", map, true);
					draw(0, 0, offset_C, R, R * C, "*", map, true);
					
					
					ok = solve(R, offset_R, C, offset_C, n_M, map);
					if(ok){
						break LOOP;
					}
					
					clear_map(R, C, map);
				}
			}
			
			System.out.println("Case #" + tc_index + ":");
			
			if(!ok){
				System.out.println("Impossible");
			}else{
				show_map(R, C, map);
			}
			
			//System.out.println(check(R, C, M, map, C - 1, R - 1) == ok ? "ok" : "no!");
		}
	}
	
	public static boolean is_ok(int x, int y, int C, int R){
		if(x < 0 || y < 0 || x >= C || y >= R){
			return false;
		}else{
			return true;
		}
	}
	
	public static String[][] random_solve(final int R, final int C, final int M, int limit){
		String[][] map = init_map(R, C);
		
		int count = 0;
		while(count < M && limit >= 0){
			limit--;
			final int x = (int) Math.random() * C;
			final int y = (int) Math.random() * R;
			
			if("*".equals(map[y][x]) || "c".equals(map[y][x])){
				continue;
			}
			map[y][x] = "*";
			
			count++;
		}
		
		return map;
	}
	
	public static boolean check(final int R, final int C, final int M, String[][] map, int s_x, int s_y){
		
		LinkedList<Integer> x_queue = new LinkedList<Integer>();
		LinkedList<Integer> y_queue = new LinkedList<Integer>();
		boolean[][] visited = new boolean[R][C];
		
		x_queue.add(s_x);
		y_queue.add(s_y);
		visited[s_y][s_x] = true;
		int count = 1;
		while(!x_queue.isEmpty()){
			final int x = x_queue.poll();
			final int y = y_queue.poll();
			
			boolean bomb_exist = false;
			
			LOOP:
			for(int dx = -1; dx <= 1; dx++){
				final int nx = x + dx;
				for(int dy = -1; dy <= 1; dy++){
					final int ny = y + dy;
					
					if(!is_ok(nx, ny, C, R)){
						continue;
					}else if("*".equals(map[ny][nx])){
						bomb_exist = true;
						break LOOP;
					}
				}
			}
			
			if(bomb_exist){
				continue;
			}
			
			for(int dx = -1; dx <= 1; dx++){
				final int nx = x + dx;
				for(int dy = -1; dy <= 1; dy++){
					final int ny = y + dy;
					
					if(!is_ok(nx, ny, C, R)){
						continue;
					}else if(visited[ny][nx]){
						continue;
					}
					
					visited[ny][nx] = true;
					x_queue.add(nx);
					y_queue.add(ny);
					count++;
				}
			}
		}
		//System.out.println(count);
		return (R * C) - count == M;
	}
	
}
