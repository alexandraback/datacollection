#python 2.7

import sys

def solve(N, H):
    hikers = list()
    for h in H:
	for i in range(0, h[1]):
            hikers.append([ h[0], h[2] + i ])
    worst_case = len(hikers)
    unavoid = 0
    complete_times = list()
    lap_times = list()
    for h in hikers:
        if (h[0] == 0):
	    unavoid += 1
	complete_times.append(float(h[1]) * (1-float(h[0])/360.0))
	lap_times.append(h[1] + float(h[1]) * (1-float(h[0])/360.0))

    if (unavoid > 0):
        print "UNAVOID"
    print complete_times
    print lap_times
    min_laps = 99999999999999
    min_index = 1
    max_index = 0
    if complete_times[0] > complete_times[1]:
        min_index = 0
        max_index = 1
    if (complete_times[min_index] < lap_times[max_index]):
        return str(0) # hug slowest til it completes; you will not be passed
    return str(1) 

def main():
    if (not len(sys.argv) == 3):
        print("Need exactly twos args: input filename and output filename")
        return
    input_data = open(sys.argv[1], 'r').read()
    output_file = open(sys.argv[2], 'w')
    split_input = input_data.split("\n")
    case_count = int(split_input[0])
    n = 1
    for i in range(0,case_count):
	count = int(split_input[n])
	h = list()
	for j in range(1, count+1):
	    h.append([int(x) for x in split_input[n+j].split(" ") ])
        print "Case #" + str(i + 1)
        print h
        res = solve(count, h)
        print "= " + res
        n += count + 1
        output_file.write("Case #" + str(i + 1) + ": " + res + "\n")
    
if __name__ == "__main__":
    main()
