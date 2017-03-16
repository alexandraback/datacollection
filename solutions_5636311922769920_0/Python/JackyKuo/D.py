import sys
def main():
	T = int(input())
	f = open("D-small.out", "w")
	for i in range(1, T+1):
		K, C, S = map(int, input().split())
		print("Case #%d:" % i, end="", file=f)
		for j in range(1, S+1):
			print(" %d" % j, end = "", file=f)
		print(file=f)
main()