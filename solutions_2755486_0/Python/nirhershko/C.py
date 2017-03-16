class Tribe:
	def __init__(self, num, tribe_info):
		self.num = num
		
		di,ni,wi,ei,si,delta_di,delta_pi,delta_si = tribe_info
		
		self.next_attack_day = di
		self.attacks_left = ni
		self.next_location = [wi,ei]
		self.strength = si
		
		self.time_interval = delta_di
		self.location_interval = delta_pi
		self.strength_delta = delta_si
	
	def next_attack(self):
		self.next_attack_day += self.time_interval
		self.attacks_left -= 1
		self.next_location = [l + self.location_interval for l in self.next_location]
		self.strength += self.strength_delta

class Wall:
	def __init__(self):
		self.ranges = []
	
	def is_vulnurable(self, tribe):
		if tribe.strength<=0:
			return False
		
		a_start,a_end = tribe.next_location
		for w_start,w_end,w_height in self.ranges:
			if w_end<a_start:
				continue
			if w_start>a_start:
				return True
			if w_height<tribe.strength:
				return True
			#this segment is protected
			a_start = w_end
			if a_start>=a_end:
				return False
		return True
	
	def grow_defences(self, tribe):
		if tribe.strength<=0:
			return
		
		a_start,a_end = tribe.next_location
		a_height = tribe.strength
		
		new_ranges = []
		for w_start,w_end,w_height in self.ranges:
			if a_end<=a_start:
				new_ranges.append((w_start,w_end,w_height))
				continue
			
			#align start
			if w_start<a_start:
				new_ranges.append((w_start,min(w_end,a_start),w_height))
				w_start = a_start
				if w_start>=w_end:
					continue
			
			if a_start<w_start:
				new_ranges.append((a_start,min(a_end,w_start),a_height))
				a_start = w_start
				if a_start>=a_end:
					new_ranges.append((w_start,w_end,w_height))
					continue
			
			#skip the attack if it is lower
			if w_height>=a_height:
				new_ranges.append((w_start,w_end,w_height))
				a_start = w_end
				continue
			
			#now the attack is stronger
			end = min(a_end,w_end)
			new_ranges.append((a_start,end,a_height))
			a_start = end
			w_start = end
			if w_start<=w_end:
				#rest of the wall..
				new_ranges.append((w_start,w_end,w_height))
				continue
		
		if a_start<a_end:
			new_ranges.append((a_start,a_end,a_height))
			
		self.ranges = new_ranges
		self._collapse()
	
	def _collapse(self):
		new_ranges = []
		for w_start,w_end,w_height in self.ranges:
			if w_start==w_end:
				continue
			if len(new_ranges)>0:
				if new_ranges[-1][1] == w_start and new_ranges[-1][2] == w_height:
					new_ranges[-1][1] = w_end
					continue
			new_ranges.append([w_start,w_end,w_height])
		self.ranges = new_ranges
	
def get_attacks_succeeded(tribes):
	show = False
	
	wall = Wall()
	attacks = 0
	while len(tribes)>0:
		next_attack_time = min([tribe.next_attack_day for tribe in tribes])
		if show:
			print "Day %d" % next_attack_time
		tribes_attacking = [tribe for tribe in tribes if tribe.next_attack_day==next_attack_time]
		for t in tribes_attacking:
			if wall.is_vulnurable(t):
				attacks += 1
				if show:
					print "Tribe %d attacks" % t.num
		for t in tribes_attacking:
			if show:
				print
				print "Upgrading wall from:"
				print wall.ranges
				print "After attack:"
				print t.next_location, t.strength
			wall.grow_defences(t)
			if show:
				print "To:"
				print wall.ranges
				print
			
			t.next_attack()
			if t.attacks_left == 0:
				tribes.remove(t)
	return attacks

def read_numbers(count=None):
	line = raw_input()
	tokens = [tok.strip() for tok in line.split(" ")]
	
	if count!=None:
		assert len(tokens) == count
	
	return map(int, tokens)

def main():
	T = read_numbers(1)[0]
	for i in range(T):
		N = read_numbers(1)[0]
		tribes = []
		for tribe in range(N):
			tribe_info = read_numbers(8)
			tribes.append(Tribe(tribe+1, tribe_info))
		num = get_attacks_succeeded(tribes)
		print "Case #%d: %d" % (i+1,num)

main()
