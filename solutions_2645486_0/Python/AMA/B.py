import networkx as nx
from random import randint
import sys
from countutil import *
import math
from decimal import *

def formula(a,count):
	return (a+2*count-2)*count
	
def make_decision(max_energy,regain,values):	
	values = sorted(values,reverse=True)
	max_act = values[0]
	rem = values[1:]
	return str(max_act*max_energy + regain*sum(rem))

def read_input(size):
	problem='B'
	reader = get_reader(problem,size)
	writer = get_writer(problem,size)
	cases= reader.next()
	for case in range(int(cases)):
		max_energy,regain,acts = [int(val) for val in reader.next().strip().split()]
		values = [int(val) for val in reader.next().strip().split()]
		decision = make_decision(max_energy,regain,values)
		writer.write( "Case #"+str(case+1)+": "+decision+'\n')
		
	increment_count(problem,size)
	writer.close()
		

if __name__=='__main__':
	size = sys.argv[1]
	read_input(size)