import itertools

case = "Case #"
data = []
t = input()

def occur(string, sub):
    count = start = 0
    while True:
        start = string.find(sub, start) + 1
        if start > 0:
            count+=1
        else:
            return count

for idx in range(t):
	score = float(0)
	occ = []
	mx = 0
	summ = 0
	prob = 0
	k, l, s = map(int, raw_input().split())
	k = raw_input()
	l = raw_input()
	if not set(list(l)).issubset(set(list(k))):
		data.append(score)
	else:
		possible = list(itertools.combinations_with_replacement(k, s))
		possible = list(set(possible))
		#print possible
		for chance in possible:
			occ.append(occur("".join(chance), l))
		#print occ
		summ = sum(occ)
		mx = max(occ)
		prob = float(summ) / len(occ)
		score = float(mx) - prob
		data.append(score)
for idx in range(t):
	print case + str(idx + 1) + ": " + str(data[idx])
#print occur("AAAA", "AAA")

