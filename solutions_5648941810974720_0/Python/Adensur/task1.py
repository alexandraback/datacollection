"ONE", "THREE"

1. for each Z in the string, output 1 zero. delete letters "ZERO" from initial string
2. for each G in the string, output 1 eight. delete "eight" from initial string
3. x - for 6
4. w - for 2
5. u - for 4
6. f - for 5
7. v - for 7
8. i - for 9
9. r - for 3
10. remaining letters - divide len() by 3. 

4
ONE - 012
WEIGHFOXTOURIST
OURNEONFOE
ETHER

import os
import string
os.chdir("C:/Users/asus/Downloads")
#reading file
with open("input.txt") as handle:
	T=int(handle.readline().strip("\n"))
	data=[]
	for t in range(T):
		data.append(handle.readline().strip("\n"))
def Remove(str,str2):
	for ch in str2:
		str=string.replace(str,ch,"",maxreplace=1)
	return str
def Solve(Str):
	result=""
	while(True):
		if len(Str)==0:
			break;
		elif "Z" in Str:
			result=result+"0"
			Str=Remove(Str,"ZERO")
		elif "G" in Str:
			result=result+"8"
			Str=Remove(Str,"EIGHT")
		elif "X" in Str:
			result=result+"6"
			Str=Remove(Str,"SIX")
		elif "W" in Str:
			result=result+"2"
			Str=Remove(Str,"TWO")
		elif "U" in Str:
			result=result+"4"
			Str=Remove(Str,"FOUR")
		elif "F" in Str:
			result=result+"5"
			Str=Remove(Str,"FIVE")
		elif "V" in Str:
			result=result+"7"
			Str=Remove(Str,"SEVEN")
		elif "I" in Str:
			result=result+"9"
			Str=Remove(Str,"NINE")
		elif "R" in Str:
			result=result+"3"
			Str=Remove(Str,"THREE")
		elif "O" in Str:
			result=result+"1"
			Str=Remove(Str,"ONE")
	result="".join(sorted(result))
	return result
with open("A-small-attempt0 (1).in") as handle:
	T=int(handle.readline().strip("\n"))
	data=[]
	for t in range(T):
		data.append(handle.readline().strip("\n"))
with open("output.txt","w") as handle:
	n=1
	for t in range(T):
		result="Case #%s: %s\n"%(n,Solve(data[t]))
		print result
		handle.write(result)
		n+=1