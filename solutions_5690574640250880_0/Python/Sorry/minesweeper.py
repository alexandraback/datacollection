import sys
def main(argv):
	file_name = argv[0]
	f = open(file_name, 'r')
	number_tests = int(f.readline())

	for count in range(number_tests):
		first_line = f.readline()
		first_line = first_line.split()

		first_line = map(int, first_line)

		row = first_line[0]
		column = first_line[1]
		mines = first_line[2]

		clear = row * column - mines
		first = True

		print "Case #" + str(count+1) + ":"
		if row == 1:
			output = ""
			for cur_col in range(column):
				if first:
					first = False
					output += "c"
				elif (cur_col < clear):
					output += "."
				else:
					output += "*"
			print output
		elif column == 1:
			for cur_row in range(row):
				if first:
					first = False
					print "c"
				elif (cur_row < clear):
					print "."
				else:
					print "*"
		elif clear == 1:
			for cur_row in range(row):
				output = ""
				for cur_col in range(column):
					if first:
						first = False
						output += "c"
					else:
						output += "*"
				print output
		elif (clear % 2 == 0 and clear > 3) or (clear > 8 and column > 2 and row > 2):
			column_stop = min(clear / 2, column)
			left_overs = clear % column_stop
			while (left_overs == 1 ):
				column_stop -= 1
				left_overs = clear % column_stop
			last_special = False
			if (column_stop * row < clear):
				column_stop = min(clear / 2, column)
				last_special = True
			for cur_row in range(row):
				output = ""
				for cur_col in range(column):
					if first:
						first = False
						output += "c"
						clear -= 1
					elif (clear > 0 and cur_col < column_stop):
						if (clear == 2 and last_special and cur_col != 0):
							output += "*"
						else:
							output += "."
							clear -= 1
					else:
						output += "*"
				print output
		else:
			print "Impossible"


if __name__ == "__main__":
   main(sys.argv[1:])
