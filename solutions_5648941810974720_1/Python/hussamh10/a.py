
def Remove06824(s):

	if 'Z' in s:
		s = s.replace('Z', '', 1);
		s = s.replace('E', '', 1);
		s = s.replace('R', '', 1);
		s = s.replace('O', '', 1);
		return (0, s)
		
	if 'X' in s:
		s = s.replace('S', '', 1);
		s = s.replace('I', '', 1);
		s = s.replace('X', '', 1);
		return (6, s)
		
	if 'G' in s:
		s = s.replace('E', '', 1);
		s = s.replace('I', '', 1);
		s = s.replace('G', '', 1);
		s = s.replace('H', '', 1);
		s = s.replace('T', '', 1);
		return (8, s)
		
	if 'W' in s:
		s = s.replace('T', '', 1);
		s = s.replace('W', '', 1);
		s = s.replace('O', '', 1);
		return (2, s)
		
	if 'U' in s:
		s = s.replace('F', '', 1);
		s = s.replace('O', '', 1);
		s = s.replace('U', '', 1);
		s = s.replace('R', '', 1);
		return (4, s)
		
	return (-1, s)

def laterRemove13(s):

	if 'O' in s:
		s = s.replace('O', '', 1);
		s = s.replace('N', '', 1);
		s = s.replace('E', '', 1);
		return (1, s)
		
	if 'T' in s:
		s = s.replace('T', '', 1);
		s = s.replace('H', '', 1);
		s = s.replace('R', '', 1);
		s = s.replace('E', '', 1);
		s = s.replace('E', '', 1);
		return (3, s)
		
	return (-1, s)

def laterRemove9(s):

	if 'N' in s:
		s = s.replace('N', '', 1);
		s = s.replace('I', '', 1);
		s = s.replace('N', '', 1);
		s = s.replace('E', '', 1);
		return (9, s)

	return (-1, s)

def laterRemove5(s):

	if 'F' in s:
		s = s.replace('F', '', 1);
		s = s.replace('I', '', 1);
		s = s.replace('V', '', 1);
		s = s.replace('E', '', 1);
		return (5, s)
		

	return (-1, s)

def laterRemove7(s):

	if 'S' in s:
		s = s.replace('S', '', 1);
		s = s.replace('E', '', 1);
		s = s.replace('V', '', 1);
		s = s.replace('E', '', 1);
		s = s.replace('N', '', 1);
		return (7, s)

	return (-1, s)


def main():

	tc = 0

	r = open('input.txt', 'r')
	w = open('out.txt', 'w')

	tc = r.readline()
	tc = int(tc)
	i = 0

	while(tc > 0):

		i += 1
		tc -= 1

		s = r.readline()
		b = 0;
		arr = []

		(b, s) = Remove06824(s)
		while(b != -1):
			arr.append(b)
			(b, s) = Remove06824(s)

		(b, s) = laterRemove13(s)
		while(b != -1):
			arr.append(b)
			(b, s) = laterRemove13(s)

		(b, s) = laterRemove7(s)
		while(b != -1):
			arr.append(b)
			(b, s) = laterRemove7(s)

		(b, s) = laterRemove9(s)
		while(b != -1):
			arr.append(b)
			(b, s) = laterRemove9(s)

		(b, s) = laterRemove5(s)
		while(b != -1):
			arr.append(b)
			(b, s) = laterRemove5(s)

		arr.sort()
		sa = " " 
		for ints in arr:
			sa += str(ints)
		case = "Case #" + str(i) + ":" + sa + '\n'
		w.write(case)

main();

# "ZERO", Z
# "SIX", X
# "EIGHT", G
# "TWO", W
# "FOUR", U
# "ONE", O but later
# "THREE", T but later 
# "NINE", N but later later
# "FIVE", I but later later later
# "SEVEN", V but later later later later
