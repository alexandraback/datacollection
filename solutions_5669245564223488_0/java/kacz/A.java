package codejam14;

import java.io.FileInputStream;
import java.io.IOException;
import java.io.PrintStream;
import java.util.*;

public class A {

	public static long MODULO = 1000000007;
	public static List<Long> factorials = new ArrayList<>();
	
	private class Car {
		char start;
		char end;
		Set<Character> middle = new HashSet<>();
		public Car(String s) {
			start = s.charAt(0);
			end = s.charAt(s.length()-1);
			char c = start;
			for(int i = 0; i < s.length(); ++i) {
				if(s.charAt(i) != c) {
					c = s.charAt(i);
					middle.add(c);
				}
			}
			int ind = s.length()-1; 
			while(s.charAt(ind) == end && ind > 0) {
				ind--;
			}
			if(s.substring(0, ind+1).indexOf(end) == -1) {
				middle.remove(end);
			}
		}
	}
	
    static Scanner in;

    public static void main(String[] args) throws IOException {
    	
    	long f = 1;
    	factorials.add(f);
    	for(int i = 1; i < 101; ++i) {
    		f = f*i % MODULO;
    		factorials.add(f);
    	}
    	
	    System.setIn(new FileInputStream("input"));
        System.setOut(new PrintStream("output"));
        in = new Scanner(System.in);
        int T = in.nextInt();
        A a = new A();
        for(int i = 1; i <= T; ++i) {
            a.solve(i);
        }
    }

    private void solve(int caseNum) {
        int N = in.nextInt();
        
        List<Car> cars = new ArrayList<>();
        for(int i = 0; i < N; ++i) {
        	String car = in.next("\\w+");
        	cars.add(new Car(car));
        }
        
        if(isImpossible(cars)) {
        	System.out.println("Case #" + caseNum + ": 0");
        	return;
        }
        
        Map<Character,Character> nextCars = new HashMap<>();
        Set<Character> starts = new HashSet<>();
        Set<Character> ends = new HashSet<>();
        Map<Character,Integer> singleLetterCars = new HashMap<>();
        for(Car car: cars) {
        	starts.add(car.start);
        	ends.add(car.end);
        	if(car.start != car.end) {
        		if(nextCars.containsKey(car.start) || nextCars.containsValue(car.end)) {
        			System.out.println("Case #" + caseNum + ": 0");
                	return;
        		} else {
        			nextCars.put(car.start, car.end);
        		}
        	} else {
        		Integer curr = singleLetterCars.get(car.start); 
        		int v = (curr == null ? 0 : curr);
        		singleLetterCars.put(car.start, v+1);
        	}
        }
        
        Set<Character> firstCars = new HashSet<>(starts);
        firstCars.removeAll(nextCars.values());
        List<Long> trains = new LinkedList<>();
        
        for(Character first : firstCars) {
//        	Set<Character> remainingCars = new HashSet<>(firstCars);
//        	remainingCars.remove(first);
//        	
        	long currentComb = 1;
        	if(singleLetterCars.containsKey(first)) {
        		currentComb = factorial(singleLetterCars.get(first));
        	}
        	char currentLetter = first;
        	
        	while(nextCars.get(currentLetter) != null) {
        		currentLetter = nextCars.get(currentLetter);
        		if(singleLetterCars.containsKey(currentLetter)) {
            		currentComb = currentComb * factorial(singleLetterCars.get(currentLetter)) % MODULO;
            	} 
        	}
        	trains.add(currentComb);
        }
        
        long result = 1;
        for(long l : trains) {
        	result = result * l % MODULO;
        }
        
        result  = result * factorial(trains.size()) % MODULO;
        
        System.out.println("Case #" + caseNum + ": " + result);
    }

	private long factorial(Integer i) {
		return factorials.get(i);
	}

	private boolean isImpossible(List<Car> cars) {
		Set<Character> middles = new HashSet<>();
		for(Car car : cars) {
			for(Character c : car.middle) {
				if(middles.contains(c)) {
					return true;
				}
				middles.add(c);
			}
		}
		for(Car car : cars) {
			if(middles.contains(car.start) || middles.contains(car.end)) {
				return true;
			}
		}
		
		return false;
	}
}
