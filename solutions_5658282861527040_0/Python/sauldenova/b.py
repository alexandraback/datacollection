#b.py
#By Saul de Nova

def main():
	T = int(raw_input())
	for t in range(1, T + 1):
		A, B, K = [int(i) for i in str(raw_input()).split(' ')]
		values = [0 for i in range(max(A, B))]
		for i in range(A):
			for j in range(B):
				values[i & j] += 1
		#print(values)
		print("Case #" + str(t) + ": " + str(sum(values[0:K])))


if __name__ == '__main__':
	main()