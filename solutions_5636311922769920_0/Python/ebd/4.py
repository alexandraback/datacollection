def main():
	T = int(raw_input())
	for cs in range(1, T + 1):
		K, _, _ = [int(x) for x in raw_input().split()]
		print 'Case #{}: {}'.format(cs, ' '.join(str(x) for x in range(1, K + 1)))

if __name__ == '__main__':
	main()