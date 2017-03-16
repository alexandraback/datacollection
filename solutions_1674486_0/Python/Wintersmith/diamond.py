import sys

class Class(object):
	def __init__(self, s):
		self.subclasses = []
		self.superclasses = []
		self.parentpaths = None
		self.childpaths = None
		self.name = s
	def add_subclass(self, c):
		self.subclasses.append(c)
	def add_superclass(self, c):
		self.superclasses.append(c)
	def get_all_superclasses(self):
		if self.parentpaths == None:
			l = [i.get_all_superclasses() for i in self.superclasses] + [self.superclasses]
			self.parentpaths = [i for sub in l for i in sub]
		return self.parentpaths
	def get_all_subclasses(self):
		if self.childpaths == None:
			l = [i.get_all_subclasses() for i in self.subclasses] + [self.subclasses]
			self.childpaths = [i for sub in l for i in sub]
		return self.childpaths
	def __str__(self):
		return "Class %s"%self.name
	__repr__ = __str__

def is_diamond_inheritance(lines):
	classes = compile_classes(lines)
	for c in classes:
		l = c.get_all_superclasses()
		if len(list(set(l))) < len(l):
			return True
		l = c.get_all_subclasses()
		if len(list(set(l))) < len(l):
			return True
	return False
	
def compile_classes(lines):
	amt = int(lines[0])
	classes = [Class(str(i+1)) for i in range(amt)]
	for i in range(1,len(lines)):
		line = [int(j) for j in lines[i].split(" ")]
		if line[0] == 0:
			continue
		current_class = classes[i-1]
		for j in range(1, line[0]+1):
			classes[line[j]-1].add_subclass(current_class)
			current_class.add_superclass(classes[line[j]-1])
	return [c for c in classes if len(c.superclasses)>0 or len(c.subclasses)>0]

if __name__ == "__main__":
	if len(sys.argv) != 2:
		print "Syntax: %s <filename>"%sys.argv[0]
		sys.exit(2)
	fin = open(sys.argv[1],"r")
	fout = open(sys.argv[1].rsplit(".",1)[0]+".out", "w")
	r = fin.read().split("\n")
	amt = int(r[0].split(" ")[0])+1
	pointer = 1
	for i in range(1,amt):
		linecount = int(r[pointer])
		lines = [r[pointer]]
		for j in range(1, linecount+1):
			lines.append(r[pointer+j])
		pointer += linecount + 1
		
		result = is_diamond_inheritance(lines)
		fout.write("Case #%d: %s"%(i, "Yes" if result else "No"))
		if i < amt-1:
			fout.write("\n")