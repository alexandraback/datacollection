import math
import sys
def getmatchingstring(num):
	if maxlen==1:
		return str(num)
	elif maxlen==2:
		if num<10:
			return "0"+str(num)	
		else:
			return str(num)
	else:
		if num<10:
			return "00"+str(num)
		elif num<100:
			return "0"+str(num)
		else:
			return str(num)

def match(s1,s2):
	for i in range(0,len(s1)):
		if s2[i]=='?':
			continue
		else:
			if s1[i]==s2[i]:
				continue
			else:
				return False
	return True

def getValue(str1,str2):
	limit=0
	if len(str1)==1:
		limit=10
	elif len(str1)==2:
		limit=100
	else:
		limit=1000
	allresults=[]
	if '?' not in str1:
		i=int(str1)
		temp1=str1
		for j in range(0,limit):						
			temp2=getmatchingstring(j)				
			if match(temp2,str2):				
				allresults.append((math.fabs(i-j),i,j))
	elif '?' not in str2:
		j=int(str2)
		temp2=str2				
		for i in range(0,limit):			
			temp1=getmatchingstring(i)			
			if match(temp1,str1):				
				allresults.append((math.fabs(i-j),i,j))
	else:
		for i in range(0,limit):
			temp1=getmatchingstring(i)
			if match(temp1,str1) :
				for j in range(0,limit):							
					temp2=getmatchingstring(j)				
					if match(temp2,str2):				
						allresults.append((math.fabs(i-j),i,j))
	newlist=sorted(allresults,key=lambda tup:(tup[0],tup[1],tup[2])	)	
	element=newlist[0]
	return (element[1],element[2])

T=int(raw_input())
maxlen=0
for i in range(1,T+1):
	text1,text2=raw_input().split(" ")
	maxlen=len(text1)
	num1,num2=getValue(text1,text2)
	if len(str(num1))<maxlen:
		num1=getmatchingstring(num1)
	if len(str(num2))<maxlen:
		num2=getmatchingstring(num2)	
	print "Case #"+str(i)+": "+str(num1)+" "+str(num2)
	sys.stderr.write('Done with ' +str(i)+"\n")