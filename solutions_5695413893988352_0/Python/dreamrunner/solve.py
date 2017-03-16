def test(word, num):
	if num < 0:
		return False
	num = str(num)
	while len(num) < len(word):
		num = "0" + num
	if len(word) != len(num):
		return False
	for i in range(len(word)):
		if word[i] != "?" and word[i] != num[i]:
			return False
	return True


def print_len(num, l):
	num = str(num)
	while len(num) < l:
		num = "0" + num
	return num


def main():
	num_of_test = int(input())

	for test_id in range(1, num_of_test + 1):
		c, j = input().split()
		print("Case #" + str(test_id) + ": ", end="")

		done = False
		for t_j_d in range(1000):
			for t_c in range(1000):
				t_j = t_c - t_j_d
				if 0 <= t_c < 1000 and test(c, t_c) and test(j, t_j):
					print(print_len(t_c, len(c)), print_len(t_j, len(j)))
					done = True
					break
				t_j = t_c + t_j_d
				if 0 <= t_c < 1000 and test(c, t_c) and test(j, t_j):
					print(print_len(t_c, len(c)), print_len(t_j, len(j)))
					done = True
					break
				if done:
					break
			if done:
				break
if __name__ == "__main__":
	main()
