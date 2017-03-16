import sys
import string



def main():
    	f=open(sys.argv[1],'r')
    	num=f.readline()
    	num=int (num)
	j=0
	cntf=0
	cntb=0
	t_cnt=0
	k=1
	xx=0
	cons=['a','e','i','o','u']
	while (num!=0):
		xx=xx+1
		zz=[]
		data=f.readline()
		data=data.rstrip()
		data=data.rsplit(' ')
		strr=data[0]
		count=int(data[1])
		#print strr,data
		while(len(strr)-count>0):
			
			m=1
			n=1
			
			for i in range(0,count):
				for j in range(0,5):
					if(strr[i]==cons[j]):
						m=0						
						break
					
			if(m==1):
				cntf=len(strr)-count+1
			flipped=strr[::-1]
			#print flipped
			for i in range(0,count):
				for j in range(0,5):
					if(flipped[i]==cons[j]):
						n=0						
						break
								
			if(n==1):
				cntb=len(strr)-count+1
			#print cntf,cntb
			if(cntf==cntb and (m==1 or n==1) ):
				t_cnt=(cntf+cntb-1)*k+t_cnt
			elif(cntf!=cntb and (m==1 or n==1) ):
				t_cnt=(cntf+cntb)*k+t_cnt
			#print t_cnt
			popping=list(strr)
			popping.pop(0)
			
			popping.pop(len(strr)-2)
			strr = ''.join(popping)
			#print strr
			cntf=0
			cntb=0
			k=k*2	
		print 'Case #'+str(xx)+': '+str(t_cnt)
		t_cnt=0
		k=1	
		num=num-1
    
if __name__== '__main__':
    main()
