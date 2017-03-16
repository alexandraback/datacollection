
def main():

	import sys
	import collections
	filename = sys.argv[1]

	with open(filename) as f:
		content = f.readlines()
	outputFile = open("outputRankAndFile.out", 'w')
	

	T = int(content[0])
	index = 0

	for test in range(T):

		index += 1 
		N = int(content[index])
		newDict = {}

		for k in range(1,2*N):
			index += 1
			items = content[index].split()

			for item in items:
				if item not in newDict:
					newDict[item] = 1
				else:
					newDict[item] += 1


				## find full price
		missing = []
		for key in newDict:
			if newDict[key]%2 : missing.append(int(key))
		
		missing.sort()
		outputStr = "Case #" + str(test+1) + ": "

		missingNumbers = " ".join(str(number) for number in missing)
		outputStr += missingNumbers
		outputStr += "\n"

		outputFile.write(outputStr)

if __name__ == '__main__':
	main()
