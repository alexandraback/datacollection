from utils import *

def main():
	prob = Problem()	
	
class Problem():
	def __init__(self):
		reader = InputReader("input.txt", input_lines=1)
		
		output = []	
		for line in reader.lines:
			numbers = map(lambda s: int(s), line.split()[1:])
			sum = 0
			for n in numbers:
				sum += n
				
			avg = float(sum) / len(numbers)
			avg_to_reach = avg*2
			
			valid_candidates = []
			for n in numbers:
				if n < avg_to_reach:
					valid_candidates.append(n)
					
			valid_candidates_sum = 0
			for n in valid_candidates:
				valid_candidates_sum += n
				
			print valid_candidates_sum + sum
			avg_to_reach = float(valid_candidates_sum + sum) / len(valid_candidates)
			print avg_to_reach
			
			out = ""
			for n in numbers:
				percentage_needed = round(((avg_to_reach - n) / sum)*100, 6)
				
				if percentage_needed < 0:
					percentage_needed = 0
					
				out += str(percentage_needed) + " "
			output.append(out[:-1])
			
		OutputWriter("output.txt", output)

if __name__ == "__main__":
    main()

