if __name__ == '__main__':
	with open('input.txt', 'r') as f:
		with open('output.txt', 'w') as o:
			num_cases = int(f.readline()) + 1
			for case in range(1, num_cases):
				num_rows = int(f.readline())
				count = {}
				for n in range(0, 2 * num_rows - 1):
					line = f.readline().split(' ')
					for soldier in line:
						try:
							count[int(soldier)] += 1
						except:
							count[int(soldier)] = 1
				missing = []
				for key in count:
					if count[key] % 2 == 1:
						missing.append(key)
				missing.sort()
				o.write('Case #{}: {}\n'.format(case, ' '.join([str(i) for i in missing])))