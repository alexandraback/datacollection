# coding: utf-8
import sys
import string

strB = ' ynficwlbkuomxsevzpdrjgthaq'
strA = ' abcdefghijklmnopqrstuvwxyz'
strC = ' yhesocvxduiglbkrztnwjpfmaq'

if __name__=='__main__':
#	table = dict()
#	for i in range(len(strA)):
#		table[strB[i]] = strA[i]
#	for k,v in sorted(table.items()):
#		print("{0} {1}".format(k,v))
	
	T = int(sys.stdin.readline())
	for tc in range(T):
		code = sys.stdin.readline().rstrip("\n")
		text = code.translate(str.maketrans(strA,strC))
		print('Case #{0}: {1}'.format(tc+1,text))
