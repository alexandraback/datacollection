import sys

def check_argv():
	if len(sys.argv) < 3:
		print("USAGE: #python cookie.py INPUT_FILE OUTPUT_FILE")
		sys.exit()

def main():
	input_file = sys.argv[1]
	output_file = sys.argv[2]
	print input_file
	print output_file
	with open(input_file, "rb") as input, open(output_file,"w") as output:
		case_count = int(input.readline())
		for case_idx in range(1, case_count+1):
			ret = "case #"+str(case_idx)+": "
			# 0: C  1: F  2: X
			cookie_count = 0.0
			cookie_rate = 2.0
			time_total = 0.0
			F_cost, F_rate, Target = map(float, input.readline().split())
			while True:
				time_to_next_F = F_cost/cookie_rate
				time_to_X = Target/cookie_rate
				time_to_X_w_new_F = time_to_next_F + Target/(cookie_rate+F_rate)
				if time_to_X <= time_to_X_w_new_F:
					time_total += time_to_X
					break
				else:
					cookie_rate += F_rate
					time_total += time_to_next_F
			time_str = "%.7f" % time_total
			ret += time_str+"\n"
			output.write(ret)


"""
line =  "case #"+str(case_count)+": "+str(ret[0])+" "+str(ret[1])+"\n"
output.write(line)
"""

if __name__ == "__main__":
	main()