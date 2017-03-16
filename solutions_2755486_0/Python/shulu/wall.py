def generate_attacks(d, n, w, e, s, dd, dp, ds):
	return [ (d+dd*i, [w+dp*i, e+dp*i] , s + ds*i) for i in range(n)]
half = 1000001
wall = 2*half*[0]

def check_attack(attack):
	d, interval, s = attack
	for i in range(interval[0], interval[1]):
		if wall[i] < s:
			return True
	return False

def set_wall(attack):
	d, interval, s = attack
	for i in range(interval[0], interval[1]):
		if wall[i] < s:
			wall[i] = s
def reset_wall():
	for i in range(2*half):
		wall[i] = 0
def count(lst):
	reset_wall()
	attacks = []
	for tu in lst:
		d, n, w, e, s, dd, dp, ds = tu
		attacks += generate_attacks(d, n, w, e, s, dd, dp, ds)
	attacks.sort(key=lambda x: x[0])
	cur_day = 0
	cur_attacks = []
	result = 0
	for attack in attacks:
		if cur_day < attack[0]:
			for cur_att in cur_attacks:
				if check_attack(cur_att):
					result +=1
			for cur_att in cur_attacks:
				set_wall(cur_att)
			cur_attacks = [attack]
			cur_day = attack[0]
		else:
			cur_attacks +=[attack]
	for cur_att in cur_attacks:
		if check_attack(cur_att):
			result +=1
	return result

for i in range(int(raw_input())):
	lst = []
	for j in range(int(raw_input())):
		lst += [map(int, raw_input().split())]
	print 'Case #%d: %d' % (i+1, count(lst))
