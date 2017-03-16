import copy
def main():
	infile = open('4.in','r')
	outfile = open('4.out','w')
	num_of_cases = int(infile.readline())
	for i in range(1,num_of_cases+1):
		num_of_weights = int(infile.readline())
		weights_naomi_deceit = [float(a) for a in infile.readline().replace("\n", "").split(" ")]
		weights_ken_deceit = [float(a) for a in infile.readline().replace("\n", "").split(" ")]
		weights_naomi_normal = copy.deepcopy(weights_naomi_deceit)
		weights_ken_normal = copy.deepcopy(weights_ken_deceit)
		points_naomi_deceit = 0
		points_naomi_normal = 0
		for j in range(0,num_of_weights):
			naomi_data = naomi_choosing_deceitful(weights_naomi_deceit,weights_ken_deceit)
			ken_chosen = ken_chossing(naomi_data[0],weights_ken_deceit)
			if(naomi_data[1] > ken_chosen):
				points_naomi_deceit = points_naomi_deceit + 1
		for j in range(0,num_of_weights):
			naomi_chosen = naomi_choosing_war(weights_naomi_normal)
			#print (naomi_chosen)
			ken_chosen = ken_chossing(naomi_chosen,weights_ken_normal)
			if(naomi_chosen > ken_chosen):
				points_naomi_normal = points_naomi_normal + 1
		outfile.write("Case #" + str(i) + ": " + str(points_naomi_deceit) + " " + str(points_naomi_normal) + "\n")
	infile.close()
	outfile.close()
def ken_chossing (chosen_naomi,weights_ken): #Ken's optimal way?
	weights_ken.sort()
	for weight in weights_ken:
		if weight > chosen_naomi:
			chosen = weight
			weights_ken.remove(weight)
			return chosen
	chosen = weights_ken[0]
	weights_ken.remove(chosen)
	return chosen
def naomi_choosing_war(weights_naomi): #Simply choose the smallest one
	weights_naomi.sort()
	chosen = weights_naomi[0]
	weights_naomi.remove(chosen)
	return chosen
def naomi_choosing_deceitful(weights_naomi,weights_ken):
	weights_naomi.sort()
	weights_ken.sort()
	claim_naomi = 0
	actual_naomi = 0
	if (weights_naomi[0] > weights_ken[0]):
		claim_naomi = weights_ken[len(weights_ken)-1] + 0.1
		actual_naomi = weights_naomi[0]
		weights_naomi.remove(weights_naomi[0])
	else:
		claim_naomi = (weights_ken[len(weights_ken)-1] + weights_ken[len(weights_ken)-2]) / 2
		actual_naomi = weights_naomi[0]
		weights_naomi.remove(weights_naomi[0])
	return [claim_naomi,actual_naomi]
if __name__ == "__main__":
	main()
