input_file = open(input("input from: "), "r")
output_file = open(input("output to: "), "w")
# input_file = open("sample_input.txt", "r")
# output_file = open("sample_output.txt", "w")
def Ken_stra(Ken, Chosen_N):
	for i in Ken:
		if i>Chosen_N:
			return i
	return Ken[0]

def war(Naomi, Ken):
	def Naomi_stra(Naomi):
		return Naomi[-1]
	Score_N = 0
	while len(Naomi):
		Chosen_N = Naomi_stra(Naomi)
		Chosen_K = Ken_stra(Ken, Chosen_N)
		if Chosen_K<Chosen_N:
			Score_N+=1
		Naomi.remove(Chosen_N)
		Ken.remove(Chosen_K)
	return Score_N

def d_war(Naomi, Ken):
	def Naomi_stra(Naomi, Ken):
		if len(Ken)==1:
			return (Naomi[0], Ken[0])
		if Naomi[0]<Ken[0]:
			return (Naomi[0],(Ken[-1]+Ken[-2])/2)
		return (Naomi[0], (Ken[-1]+1)/2)
	Score_N = 0
	while len(Naomi):
		Chosen_N, Told_N = Naomi_stra(Naomi, Ken)
		Chosen_K = Ken_stra(Ken, Told_N)
		if Chosen_K<Chosen_N:
			Score_N+=1
		Naomi.remove(Chosen_N)
		Ken.remove(Chosen_K)
	return Score_N

T = int(input_file.readline().strip())
for i in range(T):
	N = int(input_file.readline().strip())
	Naomi = sorted([float(i) for i in input_file.readline().strip().split(" ")])
	Ken = sorted([float(i) for i in input_file.readline().strip().split(" ")])
	output_file.write("Case #{}: {} {}\n".format(i+1, d_war(Naomi[:], Ken[:]), war(Naomi, Ken)))
