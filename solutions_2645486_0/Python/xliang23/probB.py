import sys
import linecache

linecache.getline(sys.argv[1], 1)

line_counter = 2

for t in range(0, int(linecache.getline(sys.argv[1], 1))):

	line = linecache.getline(sys.argv[1], line_counter)
	(E, R, N) = [int(x) for x in line.split()]
	line = linecache.getline(sys.argv[1], line_counter + 1)
	gain_list = [int(x) for x in line.split()]
	shit_list = []
	for i in range(len(gain_list)):
		shit_list.append(gain_list[i]+0.0000001*i)
	gain_list = shit_list
	usage_list = []
	for i in range(N):
		usage_list.append(0)

	total_energy = E + R * (N - 1)
	sorted_gain_list = sorted(gain_list)

	for i in range(1, N+1):

		int_place = gain_list.index(sorted_gain_list[-i])
		crap_list = []
		shitter = min(total_energy, E)
		for j in range(shitter):
			energy_attempted = shitter - j
			usage_list[int_place] = energy_attempted
			for k in range(1,N):
				for l in range(N):
					shit = min(l+k,N-1)
					if sum(usage_list[l:shit+1]) > E + k * R:
						crap_list.append(energy_attempted)

		if crap_list == []:
			energy_assigned = shitter
		else:
			energy_assigned = min(min(crap_list) - 1, total_energy)
		total_energy -= energy_assigned
		usage_list[int_place] = energy_assigned

	total_gain = 0
	for i in range(N):
		total_gain += usage_list[i] * int(gain_list[i])






	print "Case #%d: %d" % (t+1, total_gain)

	line_counter += 2

