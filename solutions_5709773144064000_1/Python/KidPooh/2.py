def main():
	infile = open('2.in','r')
	outfile = open('2.out','w')
	num_of_cases = int(infile.readline())
	for i in range(1,num_of_cases+1):
		input_line = [float(a) for a in infile.readline().replace("\n", "").split(" ")]
		c = input_line[0]
		f = input_line[1]
		x = input_line[2]
		farms = 0
		time = c/2
		while (True):
			time_no_new_farm = (x-c)/(2+f*farms)
			time_new_farm = x/(2+f*(farms+1))
			if(time_no_new_farm <= time_new_farm):
				time = time + time_no_new_farm
				break
			if(time_no_new_farm > time_new_farm):
				farms = farms + 1
				time = time + c/(2+f*farms)
				continue
		outfile.write("Case #" + str(i) +": " + str(time)+"\n")
	infile.close()
	outfile.close()
if __name__ == "__main__":
	main()
