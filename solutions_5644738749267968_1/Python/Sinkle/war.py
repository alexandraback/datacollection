import sys

def check_argv():
	if len(sys.argv) < 3:
		print("USAGE: #python war.py INPUT_FILE OUTPUT_FILE")
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
			n = int(input.readline())
			naomi_war = map(float, input.readline().split())
			ken_war = map(float, input.readline().split())
			naomi_war.sort()
			ken_war.sort()
			naomi_dwar = naomi_war[:]
			ken_dwar = ken_war[:]
			naomi_dwar.reverse()
			ken_dwar.reverse()

			war_result = 0
			dwar_result = 0

			while len(naomi_war) > 0:
				round_done = False
				for j in range(len(ken_war)):
					if naomi_war[0] < ken_war[j]:
						round_done = True
						break
				if round_done:
					del naomi_war[0]
					del ken_war[j]
				else:
					war_result += 1
					del naomi_war[0]
					del ken_war[0]						

			ken_ptr = 0
			for i in range(n):
				while ken_ptr < n:
					if naomi_dwar[i] > ken_dwar[ken_ptr]:
						dwar_result += 1
						ken_ptr += 1
						break
					else:
						ken_ptr += 1
			ret += str(dwar_result)+" "+str(war_result)+"\n"
			output.write(ret)

if __name__ == "__main__":
	main()