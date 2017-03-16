import math
import numpy as numpy


inp=open('C-small-attempt1.in', 'r')
out=open("C-small-1.out", 'w')

T=int(inp.readline())
for index in range(T):
	J, P, S, K=[int(x) for x in (inp.readline()).split()] 
	number=0;
	result="";
	Jred=J/K; Jres=J-K*Jred; Pred=P/K; Pres=P-K*Pred; Sred=S/K; Sres=S-K*Sred;
	if (Jres==0):
		Jred=Jred-1; Jres=K;
	if (Pres==0):
		Pred=Pred-1; Pres=K;
	if (Sres==0):
		Sred=Sred-1; Sres=K;
	if Sred-Pred>=1:
		number=J*P*K;
		if (Pres==K):
			modulo=P;
		else:
			modulo=(Pred+1)*K;
		for j in range(J):
			for p in range(P):
				for s in range(K):
					result=result+str(j+1)+" "+str(p+1)+" "+str((s+(j/K)*K+(p/K)*K)%(modulo) +1)+"\n"
	else:
		if(Jred==0):
			choice1=J*(Pred*K*K+Pres*Sres)
			choice2=J*((Pred-1)*K*K+Sres*Pres)
			if choice1>= choice2:
				number=J*(Pred*K*K+Pres*Sres)
				for j in range(J):
					for p in range(Pred*K):
						for s in range(K):
							result=result+str(j+1)+" "+str(p+1)+" "+str((s+(j/K)*K+(p/K)*K)%(Sres*K) +1)+"\n"
					for p in range(Pres):
						for s in range(Sres):
							result=result+str(j+1)+" "+str(p+Pred*K+1)+" "+str(s+Sred*K+1)+"\n"
			else:
				number=choice2;
				for j in range(J):
					for k in range(P):
						if (j/K)*K+(p/K)*K==Sred:
							for s in range(Sres):
								result=result+str(j+1)+" "+str(p+1)+" "+str((s+(j/K)*K+(p/K)*K)+1)+"\n"
						else:
							for s in range(K):
								result=result+str(j+1)+" "+str(p+1)+" "+str((s+(j/K)*K+(p/K)*K)%(Sred*K) +1)+"\n"
		else:
			if (Pred-Jred>=1):
				choice1=K*(Pred*K*K+Pres*Sres)+(J-K)*((Pred-1)*K*K+K*(Pres+Sres));
				choice2=K*(Pred*K*K+Pres*Sres) + (J-K)*(Pred*K*K);
				if choice2>= choice1:
					number=choice2;
					for j in range(J):
						for p in range(Pred*K):
							for s in range(K):
								result=result+str(j+1)+" "+str(p)+" "+str((s+(j/K)*K+(p/K)*K)%(Sres*K) +1)+"\n"
					for j in range(K):
						for p in range(Pres):
							for s in range(Sres):
								result=result+str(j+1)+" "+str(p+Pred*K+1)+" "+str(s+Sres*K+1)+"\n"
				else:
					number=choice1
					for j in range(J):
						for k in range(P):
							if (j/K)*K+(p/K)*K==Sred:
								for s in range(Sres):
									result=result+str(j+1)+" "+str(p+1)+" "+str((s+(j/K)*K+(p/K)*K)+1)+"\n"
							else:
								for s in range(K):
									result=result+str(j+1)+" "+str(p+1)+" "+str((s+(j/K)*K+(p/K)*K)%(Sred*K) +1)+"\n"
			else:
				number=K*(Pred*K*K+Pres*Sres)+(J-K)*((Pred-1)*K*K+K*(Pres+Sres));
				for j in range(J):
					for k in range(P):
						if (j/K)*K+(p/K)*K==Sred:
							for s in range(Sres):
								result=result+str(j+1)+" "+str(p+1)+" "+str((s+(j/K)*K+(p/K)*K)+1)+"\n"
						else:
							for s in range(K):
								result=result+str(j+1)+" "+str(p+1)+" "+str((s+(j/K)*K+(p/K)*K)%(Sred*K) +1)+"\n"

	out.write('Case #{}: {}\n'.format(index+1, number))
	out.write(result)




inp.close()
out.close()