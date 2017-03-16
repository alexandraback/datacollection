# Osmos

def getOperations(A, motes, index = 0, operations = 0):
	if index == len(motes) or operations == len(motes):
		return operations

	if motes[index] < A:
		return getOperations(A+motes[index], motes, index+1, operations)

	op_add = getOperations(A+A-1, motes, index, operations+1)
	op_delete = operations + (len(motes) - index)
	if op_delete < op_add:
		return op_delete

	return op_add


if __name__ == "__main__":
	T = int(raw_input())
	for i in xrange(T):
		A,N = map(int, raw_input().split())
		motes = map(int, raw_input().split())
		print "Case #{0}: {1}".format(i+1, getOperations(A,sorted(motes)))