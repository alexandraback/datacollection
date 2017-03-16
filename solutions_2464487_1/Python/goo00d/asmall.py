import sys
fp=open('A-large.in','r')
sys.stdin=fp
ll=input()
fout=open('outalarge.txt','w')
sys.stdout=fout
for ttcase in range(ll):
	r,t=map(int,raw_input().split(" "))
	end=int(1e18)
	start=1
	count=0
	while (end-start>0):
		count+=1
		n=(start+end)/2
		if 2*n**2+n*(2*r-1)>t:
			end=n
		elif 2*n**2+n*(2*r-1)<t:
			start=n
		else:
			break
		if count>500:
			break
	print "Case #%d:"%(ttcase+1),n

#		print ttres
#	print res
#	print "\n"
fp.close()
fout.close()