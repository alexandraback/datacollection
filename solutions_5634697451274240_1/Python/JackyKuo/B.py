import sys
def recur(a, n):
	if n == 0:
		return 0
	if n == 1:
		if a[0] == '-':
			return 1
		else:
			return 0
	if a[n-1] == '+' or a[n-1] == a[n-2]:
		return recur(a, n-1)
	else:
		return recur(a, n-2) + 2
def main():
	f = open("B_large.out", "w")
	T = int(input())
	for i in range(1, T+1):
		a = input()
		print("Case #%d: %d" % (i, recur(a, len(a))), file = f)
main()


