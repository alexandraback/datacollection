#import math
import sys

t = int(sys.stdin.readline().strip())

for i in range(t):
	l = sys.stdin.readline().strip().split()
	n = int(l[0])

	attacks = []
	for j in range(n):
		l = sys.stdin.readline().strip().split()
		di = int(l[0])
		ni = int(l[1])
		wi = int(l[2])
		ei = int(l[3])
		si = int(l[4])
		delta_di = int(l[5])
		delta_pi = int(l[6])
		delta_si = int(l[7])

		for k in range(ni):
			attack = {
				'day': di + k * delta_di,
				'w'  : wi + k * delta_pi,
				'e'  : ei + k * delta_pi,
				's'  : si + k * delta_si
			}

			p = 0
			while (p < len(attacks)) and (attacks[p]['day'] < attack['day']):
				p += 1

			attacks.insert(p, attack)


	wall = {}
	for j in range(-200, 200):
		wall[j] = 0

	wall_index = 0
	attack_index = 0
	successful_attacks = 0
	while attack_index < len(attacks):
		attack_day = attacks[attack_index]['day']
		while (attack_index < len(attacks)) and (attacks[attack_index]['day'] == attack_day):
			attack = attacks[attack_index]

			for j in range(attack['w'], attack['e']):
				if wall[j] < attack['s']:
					successful_attacks += 1
					break

			attack_index += 1

		while wall_index < attack_index:
			attack = attacks[wall_index]
			for j in range(attack['w'], attack['e']):
				if wall[j] < attack['s']:
					wall[j] = attack['s']
			wall_index += 1
		

	print "Case #" + str(i + 1) + ": " + str(successful_attacks)
