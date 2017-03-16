import networkx as nx
from random import randint
import sys
from countutil import *
import math
from decimal import *

def formula(a,count):
	return (a+2*count-2)*count
	
def make_decision(radius,amount):

	a = long(((radius+1)**2)-(radius**2))
	max_count = amount
	min_count = 0
	current = int((min_count+max_count)/2)
	while True:
		if min_count==max_count:
			current = min_count
			break
		total = formula(a,current)
		total_less = formula(a,current-1)
		#print current,total_less,total,amount
		if total> amount and total_less <= amount:
			break
		if total_less > amount:
			max_count = current
			current = int((min_count+current)/2)
		else:
			min_count = current
			current = int((max_count+current)/2)
	print 'final',radius,amount,current-1	
	return str(current-1)

def read_input(size):
	problem='A'
	reader = get_reader(problem,size)
	writer = get_writer(problem,size)
	cases= reader.next()
	for case in range(int(cases)):
		box = []
		filled=True
		radius,amount = reader.next().strip().split()
		radius = int(radius)
		amount = long(amount)
		decision = make_decision(radius,amount)
		writer.write( "Case #"+str(case+1)+": "+decision+'\n')
		
	increment_count(problem,size)
	writer.close()
		

if __name__=='__main__':
	size = sys.argv[1]
	read_input(size)