num_dict = [
	"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"
]

def main():
	num_of_test = int(input())

	for test_id in range(1, num_of_test + 1):
		chars = [c for c in input()]
		d = {}
		for c in chars:
			if c not in d.keys():
				d[c] = 0
			d[c] += 1
		n = [0] * 10
		n[0] = d["Z"] if "Z" in d.keys() else 0
		n[2] = d["W"] if "W" in d.keys() else 0
		n[4] = d["U"] if "U" in d.keys() else 0
		n[6] = d["X"] if "X" in d.keys() else 0
		n[8] = d["G"] if "G" in d.keys() else 0
		n[3] = d["H"] - n[8] if "H" in d.keys() else 0
		n[5] = d["F"] - n[4] if "F" in d.keys() else 0
		n[7] = d["S"] - n[6] if "S" in d.keys() else 0
		n[1] = d["O"] - n[0] - n[2] - n[4] if "O" in d.keys() else 0
		n[9] = (d["N"] - n[1] - n[7]) // 2 if "N" in d.keys() else 0
		print("Case #" + str(test_id) + ": ", end="")
		# ans = ""
		for digit in range(10):
			print(str(digit) * n[digit], end="")
			# ans += num_dict[digit] * n[digit]
		# ans = sorted(ans)
		# chars = sorted(chars)
		print()

if __name__ == "__main__":
	main()
