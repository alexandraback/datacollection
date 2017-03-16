from fractions import Fraction
 
def part_elf():
	for t in range(int(input())):
		f=Fraction(input())
		n,d=f.numerator,f.denominator
		print('Case #%d: %s'%(t+1,'impossible'if d&(d-1)or d>(1<<40)else d.bit_length()-n.bit_length()))
 
part_elf()