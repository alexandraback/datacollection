#!/usr/bin/python

import sys

def print_usage():
	print sys.argv[0], "<input file>", "<output file>"

char_map = {"a":"y",
            "b":"h",
            "c":"e",
            "d":"s",
            "e":"o",
            "f":"c",
            "g":"v",
            "h":"x",
            "i":"d",
            "j":"u", 
            "k":"i",
            "l":"g",
            "m":"l",
            "n":"b",
            "o":"k",
            "p":"r",
            "q":"z",
            "r":"t",
            "s":"n",
            "t":"w",
            "u":"j",
            "v":"p",
            "w":"f",
            "x":"m",
            "y":"a",
            "z":"q",
            " ":" "
           }

def solve(line):
	out = ''.join([char_map[c] for c in line])
	return out

def main():
	if len(sys.argv) != 3:
		print_usage()
		return

	in_file = open(sys.argv[1], "r")
	out_file = open(sys.argv[2], "w")

	count = 0
	case_num = 0
	for line in in_file:
		line = line.strip()
		if count == 0:
			case_num = int(line)
		else:
			out_file.write("Case #"+str(count)+": "+solve(line)+"\n")
		count += 1

	out_file.close()

if __name__ == "__main__":
	main()
