from math import *
from fractions import gcd
import random;
import os, sys;

Len = 30;
a = [0]*Len;

def change(base):
	global a, Len;
	t = base;
	ret = 1;
	for i in range(Len):
		ret = ret + t * a[i];
		t = t * base;
	ret = ret + t;
	return ret;

def geta():
	global a, Len;
	for i in range(Len):
		a[i] = random.randint(0, 1);

def mainloop():
	f = file("c_large.out", "w");
	ans = 0;
	ret = set();
	factor = [0] * 100;
	while (1):
		geta();
		pd = 1;
		x = 0;
		for i in range(2, 11):
			x = change(i);
			command = "factor " + str(x);
			result = os.popen(command).readlines()[0].strip("\n").split(" ");
			if (result[1] == str(x)):
				pd = 0;
				break;
			factor[i] = result[1];
		if ((pd == 1) and (x not in ret)):
			ans = ans + 1;
			out = "Case #1:\n1";
			for i in range(Len - 1, -1, -1):
				out = out + str(a[i]);
			out = out + "1";
			for i in range(2, 11):
				out = out + " " + factor[i];
			f.write(out + "\n");
			if (ans == 500):
				break;
	f.close();

if __name__ == "__main__":
	mainloop();
